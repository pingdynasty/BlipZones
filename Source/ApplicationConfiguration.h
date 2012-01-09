#ifndef __APPLICATIONCONFIGURATION_H__
#define __APPLICATIONCONFIGURATION_H__

#include "../JuceLibraryCode/JuceHeader.h"

class BlipSim;
class BlipClient;
class Preset;
class MidiMessageReceiver;

class ApplicationConfiguration {
public:
  static void initialise();
  static void release();
  static PropertiesFile* getApplicationProperties();
  static BlipSim* getBlipSim();
  static BlipClient* getBlipClient();
  static Preset* getPreset(int index);
  static File getPresetDirectory();
  static MidiMessageReceiver* getMidiMessageReceiver();
private:
};

#endif  // __APPLICATIONCONFIGURATION_H__
