#ifndef __APPLICATIONCONFIGURATION_H__
#define __APPLICATIONCONFIGURATION_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "BlipSim.h"
#include "SimScreen.h"
#include "BlipClient.h"
#include "MidiZonePreset.h"

class ApplicationConfiguration {
public:
  static void initialise();
  static void release();
  static PropertiesFile* getApplicationProperties();
  static MidiOutput* getMidiOutput();
  static void setMidiOutput(MidiOutput* midi);
  static BlipSim* getBlipSim();
  static BlipClient* getBlipClient();
  static SimScreen* getSimScreen();
  static void setSimScreen(SimScreen* window);
  static MidiZonePreset* getMidiZonePreset(int index);
  static File getPresetDirectory();
private:
};

#endif  // __APPLICATIONCONFIGURATION_H__
