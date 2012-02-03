#ifndef __PRESET_FACTORY_H__
#define __PRESET_FACTORY_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "Preset.h"
#include "Zone.h"
#include "Action.h"

class PresetFactory {
public:
  PresetFactory();
  void loadPreset(Preset& preset, File& file);
/*   void loadZone(Zone& zone, PropertySet& set); */
  Zone* loadZone(PropertySet& set);
  Action* loadAction(PropertySet& set);
  void savePreset(Preset& preset, File& file);
  bool saveZone(Zone* zone, PropertySet& set);
  void saveAction(Action* action, PropertySet& set);

  static Action* createAction(String type);
  static Action* createAction(uint8_t type);

  static Zone* createZone(String type);
  static Zone* createZone(uint8_t type);

  static String getActionName(uint8_t code);
  static uint8_t getActionCode(String name);

  static String getZoneName(uint8_t code);
  static uint8_t getZoneCode(String name);
private:
};

#endif  // __PRESET_FACTORY_H__
