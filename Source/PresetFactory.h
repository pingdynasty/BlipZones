#ifndef __PRESET_FACTORY_H__
#define __PRESET_FACTORY_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "Preset.h"
#include "Zone.h"
#include "Action.h"

class PresetFactory {
public:
  void loadPreset(Preset& preset, File& file);
/*   void loadZone(Zone& zone, PropertySet& set); */
  Zone* loadZone(PropertySet& set);
  Action* loadAction(PropertySet& set);
  void savePreset(Preset& preset, File& file);
  bool saveZone(Zone* zone, PropertySet& set);
  void saveAction(Action* action, PropertySet& set);

private:
};

#endif  // __PRESET_FACTORY_H__
