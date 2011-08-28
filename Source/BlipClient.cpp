#include "BlipClient.h"
#include "Serial.h"
#include "ApplicationConfiguration.h"

#define THREAD_TIMEOUT_MS  2000

#define POSITION_MSG       0x50 // 0x5 << 4
#define RELEASE_MSG        0x70 // 0x7 << 4
#define POT1_SENSOR_MSG    0x84 // 0x80 | (0x1 << 2)
#define X_SENSOR_MSG       0x88 // 0x80 | (0x2 << 2)
#define Y_SENSOR_MSG       0x8c // 0x80 | (0x3 << 2)
#define POT2_SENSOR_MSG    0x90 // 0x80 | (0x4 << 2)
#define BUTTON1_SENSOR_MSG 0x94 // 0x80 | (0x5 << 2)
#define BUTTON2_SENSOR_MSG 0x98 // 0x80 | (0x6 << 2)
#define BUTTON3_SENSOR_MSG 0x9c // 0x80 | (0x7 << 2)
#define PARAMETER_MSG      0xc0 // 0x3 << 6 B11000000

bool doSendScreenUpdates = false;

class BlipConnectionThread : public Thread {
public:
  BlipConnectionThread () : Thread(T("BlipConnectionThread")) {
    setPriority(0);
  }
  void run(){
    sleep(2000);
    BlipClient* client = ApplicationConfiguration::getBlipClient();
    BlipSim* sim = ApplicationConfiguration::getBlipSim();
    while(!threadShouldExit()){
      if(doSendScreenUpdates){
	client->sendCommand(START_LED_BLOCK);
	for(int x=0; x<10; ++x)
	  for(int y=0; y<8; ++y)
	    client->setLed(x, y, sim->getLed(x, y));
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

void BlipClient::initialise(){
  PropertiesFile* properties = ApplicationConfiguration::getApplicationProperties();
  setPort(properties->getValue("serialport"));
  setSpeed(properties->getValue("serialspeed").getIntValue());
}

void BlipClient::sendScreenUpdates(bool send){
  doSendScreenUpdates = send;
}

void BlipClient::shutdown(){
  disconnect();
}

int BlipClient::connect(){
  std::cout << "starting blipbox serial connection on " << serial->getPort() << std::endl;
  int status = serial->connect();
  serial->start();
  juce::Thread::startThread();
  connectionthread.startThread();
  sendScreenUpdates(true);
  return status;
}

int BlipClient::disconnect(){
  sendScreenUpdates(false);
  serial->stop();
  std::cout << "stopping blipbox serial connection on " << serial->getPort() << std::endl;
  connectionthread.stopThread(THREAD_TIMEOUT_MS);
  juce::Thread::stopThread(THREAD_TIMEOUT_MS);
  return serial->disconnect();
}

void BlipClient::handlePositionMessage(uint16_t x, uint16_t y){
  std::cout << "position " << x << "/" << y << std::endl;
//   Component* window = ApplicationConfiguration::getSimScreen();
//   Point<int> p = window->getPosition();
//   p = p.translated(x*window->getWidth()/1024, window->getHeight()-y*window->getHeight()/1024);
//   std::cout << "p " << p.getX() << "/" << p.getY() << std::endl;
//   Desktop::setMousePosition(p);
  ApplicationConfiguration::getBlipSim()->position(x, 1023-y); // inverted y axis
}

void BlipClient::handleParameterMessage(uint8_t pid, uint16_t value){
  static uint8_t buf[1+MIDI_ZONE_PRESET_SIZE*MIDI_ZONES_IN_PRESET];
  static uint8_t bufpos;
  std::cout << "param [" << (int)pid << "][" << (int)value << "]" << std::endl;
  if(pid == 6){
//     std::cout << "preset data " << std::dec << (int)bufpos << std::endl;
    if(bufpos < sizeof(buf))
      buf[bufpos++] = (uint8_t)value;
    else
      std::cerr << "preset buffer overflow!" << std::endl;
    if(bufpos == sizeof(buf)){
      uint8_t index = buf[0];
      std::cout << "loading preset " << std::dec << (int)index << std::endl;
      ApplicationConfiguration::getMidiZonePreset(index)->read(&buf[1]);
      bufpos = 0;
      sendScreenUpdates(true);
//       preset = client->getPreset(index);
//       for(int i=0; i<8; ++i)
//         preset->getZone(i).read(&buf[1+i*4]);
//       loadPreset(index);
    }
  }
}

void BlipClient::handleReleaseMessage(){
  std::cout << "release" << std::endl;
  ApplicationConfiguration::getBlipSim()->release();
}

int BlipClient::handle(unsigned char* data, ssize_t len){
//   std::cout << "rx[" << std::dec << len << "]" << std::endl;
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
    std::cout << "unhandled message [" << (int)type << "]" << std::endl;
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

#define REQUEST_PRESET_COMMAND (2 << 4)
#define READ_PRESET_COMMAND    (1 << 4)

void BlipClient::requestMidiZonePreset(uint8_t index){
  sendScreenUpdates(false);
  uint8_t cmd[] = { COMMAND_MESSAGE | MIDI_PRESET, REQUEST_PRESET_COMMAND | index, 0x00};
  sendSerial(cmd, sizeof(cmd));
}

void BlipClient::sendMidiZonePreset(uint8_t index){
  sendScreenUpdates(false);
  MidiZonePreset* preset = ApplicationConfiguration::getMidiZonePreset(index);
  uint8_t cmd[] = { COMMAND_MESSAGE | MIDI_PRESET, READ_PRESET_COMMAND | index};
  sendSerial(cmd, sizeof(cmd));
  uint8_t buf[MIDI_ZONE_PRESET_SIZE];
  for(int i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    preset->getZone(i)->write(buf);
    sendSerial(buf, sizeof(buf));
  }
  cmd[0] = 0x00;
  sendSerial(cmd, 1);
  sleep(1000);
  sendScreenUpdates(true);
}

void BlipClient::drawMidiZone(MidiZone* zone){
  clear();
  for(int x=std::min(zone->_from_column, zone->_to_column); x<std::max(zone->_from_column, zone->_to_column); ++x)
    for(int y=std::min(zone->_from_row, zone->_to_row); y<std::max(zone->_from_row, zone->_to_row); ++y)
      setLed(x, y, 0x20);
}

void BlipClient::sendSerial(uint8_t* data, ssize_t size){
  // send to simulator
//   ApplicationConfiguration::getBlipSim()->sendSerial(data, size);
  jassert(serial != NULL);
  // send to connected BlipBox device
  if(serial->isConnected())
    serial->writeSerial(data, size);
}
