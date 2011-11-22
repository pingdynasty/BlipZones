#ifndef __CONTROL_VALUES_H__
#define __CONTROL_VALUES_H__

#include <string.h>
#include "MidiZone.h"

#define CHANNEL_COUNT 16
#define CONTROL_VALUE_COUNT 128
#define MIDI_ZONE_COUNT 128

class ControlValues {
public:  
  ControlValues() {
    reset();
  }

  void reset(){
    memset(notes, 0, sizeof(notes));
    memset(controllers, 0, sizeof(controllers));
    memset(zones, 0, sizeof(zones));
  }

  void setNote(uint8_t channel, uint8_t pitch, int8_t velocity){
    std::cout << "set note " << (int)pitch << ": " << (int)velocity << std::endl;
    notes[channel][pitch] = velocity;
  }

  void setController(uint8_t channel, uint8_t cc, int8_t value){
    std::cout << "set cc " << (int)channel << "/" << (int)cc << ": " << (int)value << std::endl;
    controllers[channel][cc] = value;
  }

  int8_t getNote(uint8_t channel, uint8_t pitch){
    return notes[channel][pitch];
  }

  int8_t getController(uint8_t channel, uint8_t cc){
    return controllers[channel][cc];
  }

  int8_t getControlValue(uint8_t index){
    MidiZone* zone = zones[index];
    int8_t value = -1;
    if(zone != NULL){
      if((zone->_type & MIDI_ZONE_TYPE)){
	uint8_t channel = zone->_status & MIDI_CHANNEL_MASK;
	switch(zone->_status & MIDI_STATUS_MASK){
	case MIDI_NOTE_ON:
	case MIDI_NOTE_OFF:
	  value = getNote(channel, zone->_data1);
	  break;
	case MIDI_CONTROL_CHANGE:
	  value = getController(channel, zone->_data1);
	  break;
	}
      }
    }
    return value;
  }

  void setControlValue(uint8_t index, int8_t value){
    MidiZone* zone = zones[index];
    if(zone != NULL){
      if((zone->_type & MIDI_ZONE_TYPE)){
	uint8_t channel = zone->_status & MIDI_CHANNEL_MASK;
	switch(zone->_status & MIDI_STATUS_MASK){
	case MIDI_NOTE_ON:
	case MIDI_NOTE_OFF:
	  setNote(channel, zone->_data1, value);
	  break;
	case MIDI_CONTROL_CHANGE:
	  setController(channel, zone->_data1, value);
	  break;
	}
      }
    }
  }

  void configureControlValue(MidiZone* zone){
    zones[zone->_data2] = zone;
  }

private:
  MidiZone* zones[MIDI_ZONE_COUNT];
  uint8_t notes[CHANNEL_COUNT][CONTROL_VALUE_COUNT];
  uint8_t controllers[CHANNEL_COUNT][CONTROL_VALUE_COUNT];
};

#endif  // __CONTROL_VALUES_H__
