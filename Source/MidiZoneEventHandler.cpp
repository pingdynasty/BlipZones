#include "MidiZoneEventHandler.h"
#include "ApplicationConfiguration.h"
#include "defs.h"
#include "globals.h"

int8_t getControlValue(uint8_t index){
  return ApplicationConfiguration::getControlValues()->getControlValue(index);
}

void setControlValue(uint8_t index, int8_t value){
  ApplicationConfiguration::getControlValues()->setControlValue(index, value);
}

void MidiZoneEventHandler::init(){
#ifdef CV_DAC_HACK
#include "spi.h"
  spi_init();
#endif
}

void MidiZoneEventHandler::loadPreset(uint8_t index){
  preset = index;
  uint16_t offset = MIDI_PRESET_OFFSET +
    index * MIDI_ZONES_IN_PRESET * MIDI_ZONE_PRESET_SIZE;
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    zones[i].load((uint8_t*)offset);
    zones[i]._data2 = i;
//     ApplicationConfiguration::getControlValues()->configureControlValue(&zones[i]);    
    offset += MIDI_ZONE_PRESET_SIZE;
  }
  std::cout << "loaded preset " << (int)index << std::endl;
}

// void MidiZoneEventHandler::savePreset(uint8_t index){
//   preset = index;
//   index = index*MIDI_ZONES_IN_PRESET;
//   for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i)
//     zones[i].save(i+index);
// }

void MidiZoneEventHandler::press(Position& pos){
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i)
    if(zones[i].doPress() && zones[i].check(pos))
      zones[i].press(pos);
}

void MidiZoneEventHandler::release(Position& pos){
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i)
    if(zones[i].doRelease())
      zones[i].release(pos);
}

void MidiZoneEventHandler::drag(Position& pos){
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i)
    if(zones[i].doDrag() && zones[i].check(pos))
      zones[i].drag(pos);
}

//   void tap(Position& pos){
//     for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i)
//       if(zones[i].check(pos))
//         zones[i].tap(pos);
//   }

void MidiZoneEventHandler::taptap(Position& pos){
  if(blipbox.keys.pos.column == 0 && blipbox.keys.pos.row == 0)
    blipbox.setEditMode(true);
}

void MidiZoneEventHandler::tick(uint16_t counter){
//   if(counter % MIDI_ZONES_IN_PRESET == 0)
//     blipbox.leds.clear();
//   zones[counter % MIDI_ZONES_IN_PRESET].tick();
//   if(counter % MIDI_ZONES_IN_PRESET == MIDI_ZONES_IN_PRESET-1)
//     blipbox.leds.flip();
  blipbox.leds.sub(0x20);
//   blipbox.leds.clear();
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i)
    if(zones[i].doTick())
      zones[i].tick();
  blipbox.leds.flip();
}
