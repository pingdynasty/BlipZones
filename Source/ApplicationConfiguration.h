#ifndef __APPLICATIONCONFIGURATION_H__
#define __APPLICATIONCONFIGURATION_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "BlipSim.h"
#include "SimScreen.h"
#include "BlipClient.h"
#include "Preset.h"

class ApplicationConfiguration {
public:
  static void initialise();
  static void release();
  static PropertiesFile* getApplicationProperties();
  static BlipSim* getBlipSim();
  static BlipClient* getBlipClient();
  static Preset* getPreset(int index);
  static File getPresetDirectory();
private:
};

#endif  // __APPLICATIONCONFIGURATION_H__
