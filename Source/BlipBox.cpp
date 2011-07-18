#include "BlipBox.h"

int BlipBoxSerial::handle(unsigned char* data, ssize_t len){
//   std::cout << "rx";
//   for(int i=0; i<len; ++i)
//     std::cout << "\t0x" << std::hex << (int)data[i];
//   std::cout << std::endl;
  return len;
}

void BlipBox::fill(uint8_t value){
  jassert(serial != NULL);
  jassert(serial->connected());
  jassert(value < 16);
  uint8_t cmd[] = { FILL_MESSAGE | value };
  serial->writeSerial(cmd, sizeof(cmd));
}

void BlipBox::setLed(uint8_t x, uint8_t y, uint8_t brightness){
  jassert(serial != NULL && serial->connected());
  uint8_t cmd[] = { SET_LED_MESSAGE, x*16+y, brightness };
  serial->writeSerial(cmd, sizeof(cmd));
}

void BlipBox::sendMidiZonePreset(MidiZonePreset& preset){
  uint8_t cmd[] = { COMMAND_MESSAGE | 12 };
  serial->writeSerial(cmd, 1);
  cmd[0] = 1 << 4 | preset.getIndex();
  serial->writeSerial(cmd, 1);
  uint8_t buf[4];
  for(int i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    preset.getZone(i).write(buf);
    serial->writeSerial(buf, sizeof(buf));
  }
  cmd[0] = 0x00;
  serial->writeSerial(cmd, 1);
}

void BlipBox::drawMidiZone(MidiZone& zone){
  std::cout << "x " << (int)zone._from_x << "-" << (int)zone._to_x << std::endl;
  std::cout << "y " << (int)zone._from_y << "-" << (int)zone._to_y << std::endl;
  clear();
  for(int x=std::min(zone._from_x, zone._to_x); x<std::max(zone._from_x, zone._to_x); ++x)
    for(int y=std::min(zone._from_y, zone._to_y); y<std::max(zone._from_y, zone._to_y); ++y)
      setLed(x, y, 0xff);
}
