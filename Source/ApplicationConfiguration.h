#ifndef __APPLICATIONCONFIGURATION_H__
#define __APPLICATIONCONFIGURATION_H__

#include "../JuceLibraryCode/JuceHeader.h"

class BlipSim;
class SimScreen;
class BlipClient;
class MidiZonePreset;
class ControlValues;
class MidiMessageReceiver;

class ApplicationConfiguration {
public:
  static void initialise();
  static void release();
  static PropertiesFile* getApplicationProperties();
  static BlipSim* getBlipSim();
  static BlipClient* getBlipClient();
  static MidiZonePreset* getMidiZonePreset(int index);
  static File getPresetDirectory();
  static ControlValues* getControlValues();
  static MidiMessageReceiver* getMidiMessageReceiver();
private:
};

#endif  // __APPLICATIONCONFIGURATION_H__
