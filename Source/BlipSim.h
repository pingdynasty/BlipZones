#ifndef __BLIPSIM_H__
#define __BLIPSIM_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include <inttypes.h>
#include "Position.h"

class BlipSim {
private:
  Thread* blipthread;
  Thread* timer0;
public:
  BlipSim(){}
  void initialise();
  void shutdown();
  void start();
  void stop();
  void setMidiOutput(String name);
/*   void setMidiOutput(MidiOutput* midiout); */
  void sendSerial(uint8_t* data, ssize_t size);
  uint8_t getLed(uint8_t x, uint8_t y);
  bool isPressed();
  Position& getPosition();

  void position(uint16_t x, uint16_t y);
  void release();
};

#endif  // __BLIPSIM_H_
