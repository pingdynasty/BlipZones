#ifndef __PRESET_FACTORY_H__
#define __PRESET_FACTORY_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "Preset.h"
#include "Zone.h"
#include "Action.h"

// class ActionConfiguration {
// public:
//   uint8_t status;
//   uint8_t minimum;
//   uint8_t maximum;
//   uint16_t data;
//   uint8_t data1;
//   int8_t data2;

//   Action* createAction(){
//     uint8_t data[8];
//     data[3] = status;
//     data[4] = minimum;
//     data[5] = maximum;
//     data[6] = data1;
//     data[7] = data2;
//     Action* action = Action::createAction(data);
//     action->read(data);
//     return action;
//   }
// };

class PresetFactory {
public:
  void loadPreset(Preset& preset, File& file);
  void loadZone(Zone& zone, PropertySet& set);
  Action* loadAction(PropertySet& set);
  void savePreset(Preset& preset, File& file);
  void saveZone(Zone* zone, PropertySet& set);
  void saveAction(Action* action, PropertySet& set);

private:
};

#endif  // __PRESET_FACTORY_H__
