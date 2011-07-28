#include "MidiZone.h"

// #define NOTE_ZONE_BIT      1<<2
// #define BUTTON_ZONE_BIT    1<<3
// #define HORIZONTAL_CC      1
// #define VERTICAL_CC        2
// #define CC_PUSH_BUTTON     1 | BUTTON_ZONE_BIT
// #define CC_TOGGLE_BUTTON   2 | BUTTON_ZONE_BIT
// #define HORIZONTAL_NOTE    1 | NOTE_ZONE_BIT
// #define VERTICAL_NOTE      2 | NOTE_ZONE_BIT
// #define NOTE_PUSH_BUTTON   1 | NOTE_ZONE_BIT | BUTTON_ZONE_BIT
// #define NOTE_TOGGLE_BUTTON 2 | NOTE_ZONE_BIT | BUTTON_ZONE_BIT
// #define PRESET_BUTTON      0

#define NOTE_CC_ZONE_BIT             (1<<1)
#define BUTTON_SLIDER_ZONE_BIT       (1<<2)
#define HORIZONTAL_VERTICAL_ZONE_BIT (1<<3)
#define MOMENTARY_TOGGLE_ZONE_BIT    (1<<3)
#define INVERTED_ZONE_BIT            (1<<0)

uint8_t typecodes[] = {
//     typeComboBox->addItem (L"Horizontal CC Slider", 1);
  HORIZONTAL_VERTICAL_ZONE_BIT,
//     typeComboBox->addItem (L"Vertical CC Slider", 2);
    0,
//     typeComboBox->addItem (L"Horizontal Note Player", 3);
    NOTE_CC_ZONE_BIT | HORIZONTAL_VERTICAL_ZONE_BIT,
//     typeComboBox->addItem (L"Vertical Note Player", 4);
    NOTE_CC_ZONE_BIT,
//     typeComboBox->addItem (L"Note Push Button", 5);
    NOTE_CC_ZONE_BIT | BUTTON_SLIDER_ZONE_BIT | MOMENTARY_TOGGLE_ZONE_BIT,
//     typeComboBox->addItem (L"Note Toggle Button", 6);
    NOTE_CC_ZONE_BIT | BUTTON_SLIDER_ZONE_BIT,
//     typeComboBox->addItem (L"CC Push Button", 7);
    BUTTON_SLIDER_ZONE_BIT | MOMENTARY_TOGGLE_ZONE_BIT,
//     typeComboBox->addItem (L"CC Toggle Button", 8);
    BUTTON_SLIDER_ZONE_BIT,
//     typeComboBox->addItem (L"Inverted Horizontal CC Slider", 9);
    HORIZONTAL_VERTICAL_ZONE_BIT | INVERTED_ZONE_BIT,
//     typeComboBox->addItem (L"Inverted Vertical CC Slider", 10);
    INVERTED_ZONE_BIT
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
//   if(_type & NOTE_ZONE_BIT)
//     _status |= 0x80;
//   else
//     _status |= 0xb0;
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
