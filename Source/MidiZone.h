#ifndef __MIDIZONE_H__
#define __MIDIZONE_H__

#include <stdint.h>

class MidiZone {
private:
public:
  uint8_t _type;
  uint8_t _status;
  int8_t _data1, _data2;
  int8_t _from_x, _to_x;
  int8_t _from_y, _to_y;
/*   void channelMessage(uint8_t data1, uint8_t data2); */
public:
  MidiZone();
//   virtual ~MidiZone();
  void read(const uint8_t* data);
  void write(uint8_t* data);
  uint8_t getChannel(){
    return _status & 0x0f;
  }
  uint8_t getTypeCode(){
    return _status >> 4;
  }
  uint8_t getTypeIndex();
  void setTypeIndex(uint8_t index);
/*   void save(uint8_t index); */
/*   void load(uint8_t index); */
/*   inline bool check(const Position& pos){ */
/*     return _from_x <= pos.column && pos.column < _to_x && */
/*            _from_y <= pos.row && pos.row < _to_y; */
/*   } */
//   bool check(uint8_t x, uint8_t y){
//     return _from_x<=x && x<_to_x && _from_y<=y && y<_to_y;
//   }
/*   void release(Position& pos); */
/*   uint8_t getx(); */
/*   uint8_t gety(); */
/*   void press(Position& pos); */
/*   void drag(Position& pos); */
/*   void tap(Position& pos); */
/*   void tick(); */
};

#define MIDI_ZONE_PRESETS 5
#define MIDI_ZONES_IN_PRESET 8

class MidiZonePreset {
private:
  MidiZone zones[MIDI_ZONES_IN_PRESET];
public:
  MidiZonePreset();
  uint8_t preset;
  uint8_t getIndex(){
    return preset;
  }
  MidiZone& getZone(uint8_t zone){
    return zones[zone];
  }

//   void loadPreset(int index){
//     preset = index;
//     index = index*MIDI_ZONES_IN_PRESET;
//     for(int i=0; i<MIDI_ZONES_IN_PRESET; ++i)
//       zones[i].load(i+index);
//   }

//   void savePreset(int index){
//     preset = index;
//     index = index*MIDI_ZONES_IN_PRESET;
//     for(int i=0; i<MIDI_ZONES_IN_PRESET; ++i)
//       zones[i].save(i+index);
//   }

};
#endif  // __MIDIZONE_H__
