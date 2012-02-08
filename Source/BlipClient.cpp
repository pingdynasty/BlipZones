#include "BlipClient.h"
#include "Protocol.h"
#include "Serial.h"
#include "ApplicationConfiguration.h"
#include "PresetReader.h"
#include "BlipSim.h"
#include "Command.h"

#define THREAD_TIMEOUT_MS  2000
#define MIDI_ZONE_PRESET_LENGTH 1+MIDI_ZONES_IN_PRESET*MIDI_ZONE_PRESET_SIZE+1

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

bool doSendScreenUpdates = false;

#define LED_COLUMNS       10
#define LED_ROWS          8

class BlipConnectionThread : public Thread {
private:
  uint8_t leds[LED_COLUMNS][LED_ROWS];
public:
  BlipConnectionThread () : Thread(T("BlipConnectionThread")) {
    setPriority(0);
    memset(leds, 0, sizeof(leds));
  }
  void run(){
    sleep(2000);
    BlipClient* client = ApplicationConfiguration::getBlipClient();
    BlipSim* sim = ApplicationConfiguration::getBlipSim();
    while(!threadShouldExit()){
      if(doSendScreenUpdates){
	client->sendCommand(START_LED_BLOCK);
	for(int x=0; x<LED_COLUMNS; ++x){
	  for(int y=0; y<LED_ROWS; ++y){
	    uint8_t led = sim->getLed(x, y);
	    if(led != leds[x][y]){
	      leds[x][y] = led;
	      client->setLed(x, y, led);
	    }
	  }
	}
	client->sendCommand(END_LED_BLOCK);
      }
      sleep(20);
    }
  }
};

BlipConnectionThread connectionthread;

BlipClient::BlipClient()
  : Thread(T("BlipClient")){
  serial = Serial::createSerial();
  serial->setSerialCallback(this);
  setPriority(0);
}

BlipClient::~BlipClient(){
  delete serial;
}

// void BlipClient::initialise(){
// }

bool BlipClient::isConnected(){
  return serial->isConnected();
}

void BlipClient::run(){
  serial->run();
  waitForThreadToExit(-1); // wait for as long as it takes    
}

void BlipClient::setPort(const juce::String& aport){
  serial->setPort(aport);
}

void BlipClient::setSpeed(int aspeed){
  serial->setSpeed(aspeed);
}

void BlipClient::sendScreenUpdates(bool send){
  doSendScreenUpdates = send;
}

int BlipClient::connect(){
  std::cout << "starting blipbox serial connection on " << serial->getPort() << std::endl;
  int status = serial->connect();
  if(status >= 0){
    serial->start();
    juce::Thread::startThread();
    connectionthread.startThread();
    sendScreenUpdates(true);
    clear();
    ApplicationConfiguration::getBlipSim()->clear();
  }
  return status;
}

int BlipClient::disconnect(){
  sendScreenUpdates(false);
  serial->stop();
  serial->disconnect();
  std::cout << "stopping blipbox serial connection on " << serial->getPort() << std::endl;
  connectionthread.stopThread(THREAD_TIMEOUT_MS);
  juce::Thread::stopThread(THREAD_TIMEOUT_MS);
  return 0;
}

void BlipClient::shutdown(){
  disconnect();
}

void BlipClient::handlePositionMessage(uint16_t x, uint16_t y){
//   std::cout << "position " << x << "/" << y << std::endl;
  ApplicationConfiguration::getBlipSim()->position(x, 1023-y); // inverted y axis
}

void BlipClient::handleParameterMessage(uint8_t pid, uint16_t value){
  static PresetReader* reader = NULL;
  static uint8_t position = 0;
  static uint8_t index = 0;
//   std::cout << "param [" << (int)pid << "][" << (int)value << "]" << std::endl;
  if(pid == 6){
//     std::cout << "preset data " << std::dec << (int)position << std::endl;
    if(position == 0){
      delete reader;
      index = value;
      Preset* preset = ApplicationConfiguration::getPreset(index);
      reader = new PresetReader(preset);
    }
    if(position++ < MIDI_ZONE_PRESET_LENGTH){
      reader->serialInput((unsigned char)value);
    }else{
      std::cout << "loading preset " << std::dec << (int)index << std::endl;
      position = 0;
      delete reader;
      sendScreenUpdates(true);
    }
  }
}

void BlipClient::handleReleaseMessage(){
//   std::cout << "release" << std::endl;
  ApplicationConfiguration::getBlipSim()->release();
}

int BlipClient::handle(unsigned char* data, size_t len){
//   std::cout << "rx";
//   for(int i=0; i<len; ++i)
//     std::cout << "\t0x" << std::hex << (int)data[i];
//   std::cout << std::endl;
  uint8_t type = data[0];
  if((type >> 6) == 0x3){
  // parameter msg: 11ppppvv vvvvvvvv
    if(len < 2)
      return 0;
//     uint8_t pid = (type << 2) >> 4;
    uint8_t pid = (type >> 2) & 0x0f;
    uint16_t value = ((type & 0x3) << 8) | data[1];
    handleParameterMessage(pid, value);
    return 2;
  }else if((type >> 4) == 0x5){
    // position msg: 0101xxxx xxxxxxyy yyyyyyyy
      if(len < 3)
      return 0;
    uint16_t x = ((type & 0xf) << 6) | (data[1] >> 2);
    uint16_t y = ((data[1] & 0x3) << 8) | data[2];
    handlePositionMessage(x, y);
    return 3;
  }else if(type == RELEASE_MSG){
    // release message
    handleReleaseMessage();
    return 1;
  }else{
    std::cerr << "unhandled message [" << (int)type << "]" << std::endl;
    return len;
  }
}

void BlipClient::fill(uint8_t value){
  jassert(value < 16);
  uint8_t cmd[] = { FILL_MESSAGE | value };
  sendSerial(cmd, sizeof(cmd));
}

void BlipClient::clear(){
  fill(0);
}

void BlipClient::setLed(uint8_t x, uint8_t y, uint8_t brightness){
  uint8_t cmd[] = { SET_LED_MESSAGE, x*16+y, brightness };
  sendSerial(cmd, sizeof(cmd));
}

void BlipClient::sendCommand(Command command){
  uint8_t cmd[] = { COMMAND_MESSAGE | command};
  sendSerial(cmd, sizeof(cmd));  
}

void BlipClient::requestPreset(uint8_t index){
  sendScreenUpdates(false);
  uint8_t cmd[] = { COMMAND_MESSAGE | MIDI_PRESET, PRESET_REQUEST_COMMAND | index, 0x00};
  sendSerial(cmd, sizeof(cmd));
}

void BlipClient::sendPreset(uint8_t index){
  sendScreenUpdates(false);
  Preset* preset = ApplicationConfiguration::getPreset(index);
  uint8_t cmd[] = { COMMAND_MESSAGE | MIDI_PRESET, PRESET_RECEIVE_COMMAND | index};
  sendSerial(cmd, sizeof(cmd));
  uint8_t buf[MIDI_ZONE_PRESET_SIZE];
  // todo: move this code to elsewhere
  // todo: sanity check and clean data: select preset 0 <= data1 < 8, et c.
  // todo: checksum
  for(int i=0; i<MIDI_ZONES_IN_PRESET; ++i){
//     preset->getZone(i)->write(buf);
    sendSerial(buf, sizeof(buf));
  }
  cmd[0] = 0x00;
  sendSerial(cmd, 1);
  sleep(1000);
  sendScreenUpdates(true);
  ApplicationConfiguration::getBlipSim()->clear();
  ApplicationConfiguration::getBlipClient()->clear();
}

void BlipClient::drawZone(Zone* zone){
  clear();
  for(int x=std::min(zone->from.getColumn(), zone->to.getColumn()); x<std::max(zone->from.getColumn(), zone->to.getColumn()); ++x)
    for(int y=std::min(zone->from.getRow(), zone->to.getRow()); y<std::max(zone->from.getRow(), zone->to.getRow()); ++y)
      setLed(x, y, 0x20);
}

void BlipClient::sendSerial(uint8_t* data, size_t size){
  // send to simulator
//   ApplicationConfiguration::getBlipSim()->sendSerial(data, size);
  jassert(serial != NULL);
  // send to connected BlipBox device
  if(serial->isConnected())
    serial->writeSerial(data, size);
}
