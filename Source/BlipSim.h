#ifndef __BLIPSIM_H__
#define __BLIPSIM_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include <inttypes.h>
#include "Position.h"
#include "Animator.h"
#include "EventHandler.h"
#include "Event.h"
#include "Preset.h"

class BlipSim {
private:
  Thread* blipthread;
  Thread* timer0;
public:
  BlipSim();
  void shutdown();
  void start();
  void stop();
  void doMidi(bool doit);
  void setMidiOutput(String name);
/*   void setMidiOutput(MidiOutput* midiout); */
  void setAnimator(Animator* animator);
  void setEventHandler(EventHandler* handler);
  void sendSerial(uint8_t* data, size_t size);
  void flip();
  void clear();
  void fill(uint8_t value);
  void fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t brightness);
  void setLed(uint8_t x, uint8_t y, uint8_t brightness);
  uint8_t getLed(uint8_t x, uint8_t y);
  bool isPressed();
  Position& getPosition();
  void setPreset(Preset* preset);
/*   Preset* getPreset(); */
  uint8_t getPresetIndex();
  void setPresetIndex(uint8_t index);
  void position(uint16_t x, uint16_t y);
  void release();
  void handle(MidiEvent& event);
  uint16_t getControlVoltage(uint8_t channel);
};

#endif  // __BLIPSIM_H_
