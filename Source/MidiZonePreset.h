#ifndef __MIDIZONEPRESET_H__
#define __MIDIZONEPRESET_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiZone.h"
#include "MidiZoneEventHandler.h"

class MidiZonePreset : public MidiZoneEventHandler {
public:
  MidiZonePreset();
  ~MidiZonePreset(){}
  void reset();
  void start();
  void stop();
  uint8_t getIndex();
  void setIndex(uint8_t _index);
  MidiZone* getZone(uint8_t index);
  MidiZone* getSelectedZone();
  uint8_t getSelectedZoneIndex();
  void selectZone(uint8_t index);
  void taptap(Position& pos);
  void read(const uint8_t* data);
  void saveFile(const File& file);
  void loadFile(const File& file);
  void tick(uint16_t counter);
  void loadPreset(uint8_t index);
private:
  void setSelectedPreset();
  int index;
  int selected; // selected zone
};
#endif  // __MIDIZONEPRESET_H__
