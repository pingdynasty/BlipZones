#ifndef __MIDIZONEPRESET_H__
#define __MIDIZONEPRESET_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiZone.h"
#include "MidiZoneEventHandler.h"
#include "globals.h"

class MidiZonePreset : public Thread, public MidiZoneEventHandler {
public:
  MidiZonePreset()
    : Thread(T("MidiZonePreset")){
    for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i){
      zones[i]._type = MIDI_ZONE_TYPE | HORIZONTAL_VERTICAL_ZONE_BIT | NO_DISPLAY_TYPE;
//       zones[i]._type = EMPTY_ZONE_TYPE;
      zones[i]._status = MIDI_CONTROL_CHANGE;
      zones[i]._data1 = 0;
      zones[i]._min = 0;
      zones[i]._max = 127;
      zones[i]._from_column = 0;
      zones[i]._to_column = 0;
      zones[i]._from_row = 0;
      zones[i]._to_row = 0;
    }
    uint8_t channel = 5;
    zones[0]._to_column = 10;
    zones[0]._to_row = 8;
    zones[0]._type = MIDI_ZONE_TYPE | HORIZONTAL_VERTICAL_ZONE_BIT | BAR_DISPLAY_TYPE;
    zones[0]._status = MIDI_CONTROL_CHANGE | channel;
    zones[0]._min = 0;
    zones[0]._max = 127;
    zones[0]._data1 = 40;

    zones[1]._to_column = 10;
    zones[1]._to_row = 8;
    zones[1]._type = MIDI_ZONE_TYPE | BAR_DISPLAY_TYPE;
    zones[1]._status = MIDI_CONTROL_CHANGE | channel;
    zones[1]._min = 0;
    zones[1]._max = 127;
    zones[1]._data1 = 41;

    selected = 0;
  }

  ~MidiZonePreset(){
    if(isThreadRunning())
      stopThread(10);
  }

  void run(){
    while(!threadShouldExit()){
      tick(0);
      sleep(10);
//       yield();
    }
  }

  void start(){
    blipbox.eventhandler = this;
    blipbox.animator = this;
//     startThread();
  }

  void stop(){
//     stopThread(10);
    blipbox.animator = NULL;
    blipbox.eventhandler = &blipbox.defaulthandler;
  }

  uint8_t getIndex(){
    return preset;
  }

  void setIndex(uint8_t _index){
    preset = _index;
  }

  MidiZone* getZone(uint8_t index){
    return &zones[index];
  }

  uint8_t getSelectedZoneIndex(){
    return selected+1;
  }

  void selectZone(uint8_t index){
    if(index > 0 && index <= MIDI_ZONES_IN_PRESET)
    selected = index-1;
  }

  void tick(uint16_t counter){
    MidiZone* zone = &zones[selected];
    for(int x=std::min(zone->_from_column, zone->_to_column); x<std::max(zone->_from_column, zone->_to_column); ++x)
      for(int y=std::min(zone->_from_row, zone->_to_row); y<std::max(zone->_from_row, zone->_to_row); ++y)
	blipbox.leds.setLed(x, y, 0x80);
    MidiZoneEventHandler::tick(counter);
  }

private:
  uint8_t selected; // selected zone
};
#endif  // __MIDIZONEPRESET_H__
