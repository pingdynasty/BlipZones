#include "BlipClient.h"
#include "globals.h"

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

void BlipClient::handlePositionMessage(uint16_t x, uint16_t y){
  std::cout << "position " << x << "/" << y << std::endl;
  if(handler)
    handler->handlePositionMessage(x, y);
}

void BlipClient::handleParameterMessage(uint8_t pid, uint16_t value){
  std::cout << "param " << (int)pid << ":" << value << std::endl;
  if(handler)
    handler->handleParameterMessage(pid, value);
}

void BlipClient::handleReleaseMessage(){
  std::cout << "release" << std::endl;
  if(handler)
    handler->handleReleaseMessage();
}

int BlipClient::handle(unsigned char* data, ssize_t len){
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
  }
  return len;
}

void BlipClient::fill(uint8_t value){
  jassert(serial != NULL);
//   jassert(serial->connected());
  jassert(value < 16);
  uint8_t cmd[] = { FILL_MESSAGE | value };
  serial->writeSerial(cmd, sizeof(cmd));
}

void BlipClient::setLed(uint8_t x, uint8_t y, uint8_t brightness){
  jassert(serial != NULL);
//   jassert(serial->connected());
  uint8_t cmd[] = { SET_LED_MESSAGE, x*16+y, brightness };
  serial->writeSerial(cmd, sizeof(cmd));
}

#define REQUEST_PRESET_COMMAND (2 << 4)
#define READ_PRESET_COMMAND    (1 << 4)

void BlipClient::requestMidiZonePreset(uint8_t index){
  uint8_t cmd[] = { COMMAND_MESSAGE | 12,  REQUEST_PRESET_COMMAND | index, 0x00};
  serial->writeSerial(cmd, sizeof(cmd));
}

void BlipClient::sendMidiZonePreset(){
  uint8_t cmd[] = { COMMAND_MESSAGE | 12 };
  serial->writeSerial(cmd, 1);
  cmd[0] = READ_PRESET_COMMAND | blipbox.midizones.preset;
  serial->writeSerial(cmd, 1);
  uint8_t buf[4];
  for(int i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    blipbox.midizones.getZone(i).write(buf);
    serial->writeSerial(buf, sizeof(buf));
  }
  cmd[0] = 0x00;
  serial->writeSerial(cmd, 1);
}

void BlipClient::drawMidiZone(MidiZone& zone){
  std::cout << "x " << (int)zone._from_column << "-" << (int)zone._to_column << std::endl;
  std::cout << "y " << (int)zone._from_row << "-" << (int)zone._to_row << std::endl;
  clear();
  for(int x=std::min(zone._from_column, zone._to_column); x<std::max(zone._from_column, zone._to_column); ++x)
    for(int y=std::min(zone._from_row, zone._to_row); y<std::max(zone._from_row, zone._to_row); ++y)
      setLed(x, y, 0xff);
}
