#ifndef __APPLICATIONCONFIGURATION_H__
#define __APPLICATIONCONFIGURATION_H__

#include "../JuceLibraryCode/JuceHeader.h"

class ApplicationConfiguration {
public:
  static MidiOutput* getMidiOutput();
  static void setMidiOutput(MidiOutput* midi);
private:
};

#endif  // __APPLICATIONCONFIGURATION_H__
