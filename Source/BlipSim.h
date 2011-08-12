#ifndef __BLIPSIM_H__
#define __BLIPSIM_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include <inttypes.h>

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
  void sendSerial(uint8_t* data, ssize_t size);
};

#endif  // __BLIPSIM_H_
