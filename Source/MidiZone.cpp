#include "MidiZone.h"

#define NOTE_ZONE_BIT      1<<2
#define BUTTON_ZONE_BIT    1<<3
#define HORIZONTAL_CC      1
#define VERTICAL_CC        2
#define CC_PUSH_BUTTON     1 | BUTTON_ZONE_BIT
#define CC_TOGGLE_BUTTON   2 | BUTTON_ZONE_BIT
#define HORIZONTAL_NOTE    1 | NOTE_ZONE_BIT
#define VERTICAL_NOTE      2 | NOTE_ZONE_BIT
#define NOTE_PUSH_BUTTON   1 | NOTE_ZONE_BIT | BUTTON_ZONE_BIT
#define NOTE_TOGGLE_BUTTON 2 | NOTE_ZONE_BIT | BUTTON_ZONE_BIT
#define PRESET_BUTTON      0

uint8_t typecodes[] = {
    HORIZONTAL_CC,
    VERTICAL_CC,
    HORIZONTAL_NOTE,
    VERTICAL_NOTE,
    NOTE_PUSH_BUTTON,
    NOTE_TOGGLE_BUTTON,
    CC_PUSH_BUTTON,
    CC_TOGGLE_BUTTON,
    PRESET_BUTTON
};

MidiZone::MidiZone()
  : _type(typecodes[0]), _status(0), _data1(0), _from_x(0), _to_x(0), _from_y(0), _to_y(0)
{}

uint8_t MidiZone::getTypeIndex(){
  for(int i=0; i<sizeof(typecodes); ++i)
    if(typecodes[i] == _type)
      return i;
  return -1;
}

void MidiZone::setTypeIndex(uint8_t index){
  if(index < sizeof(typecodes))
    _type = typecodes[index];
}

// uint8_t MidiZonePreset::getTypeCode(){
//   uint8_t index = _status >> 4;
//   if(index < sizeof(typecodes))
//     return typecodes[index];
//   return -1;
// }

void MidiZone::read(const uint8_t* data){
  _type =   (data[0] >> 4);
  _status = data[0] & 0x0f; // set channel
  _data1 =  data[1];
  _from_x = data[2] >> 4;
  _from_y = data[2] & 0x0f;
  _to_x =   data[3] >> 4;
  _to_y =   data[3] & 0x0f;
  _data2 = 0;
  if(_type & NOTE_ZONE_BIT)
    _status |= 0x80;
  else
    _status |= 0xb0;
}

void MidiZone::write(uint8_t* data){
  data[0] = (_type << 4) | (_status & 0x0f);
  data[1] = _data1;
  data[2] = (_from_x << 4) | _from_y;
  data[3] = (_to_x << 4) | _to_y;
}

// uint8_t MidiZone::write(uint8_t* data){
  
// }

MidiZonePreset::MidiZonePreset()
  : preset(0)
{}

// void MidiZone::save(uint8_t index){
//   index = MIDI_PRESET_OFFSET+index*MIDI_ZONE_PRESET_SIZE;
//   uint8_t buf[MIDI_ZONE_PRESET_SIZE];
//   write(buf);
//   eeprom_write_block(buf, (uint8_t*)index, sizeof(buf));
// }

// void MidiZone::load(uint8_t index){
//   index = MIDI_PRESET_OFFSET+index*MIDI_ZONE_PRESET_SIZE;
//   uint8_t buf[MIDI_ZONE_PRESET_SIZE];
//   eeprom_read_block(buf, (uint8_t*)index, sizeof(buf));
//   read(buf);
// }
