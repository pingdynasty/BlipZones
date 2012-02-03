
#include "PresetFactory.h"

#include "OscAction.h"

#include "defs.h"
#include <inttypes.h>
#include <string.h>

#define FILE_FORMAT_VERSION 2

static HashMap<String, int> *actions = NULL;
HashMap<String, int>* getActionTypes(){
  if(actions == NULL){
    actions = new HashMap<String, int>();
    actions->set("Control Change",        MIDI_CONTROL_CHANGE);
    actions->set("Note On",               MIDI_NOTE_ON);
    actions->set("Pitch Bend",            MIDI_PITCH_BEND);
    actions->set("Channel Pressure",      MIDI_CHANNEL_PRESSURE);
    actions->set("Polyphonic Aftertouch", MIDI_CHANNEL_PRESSURE);
    actions->set("Note Range",            MIDI_NOTE_RANGE_ACTION_TYPE);
    actions->set("NRPN",                  MIDI_NRPN_ACTION_TYPE);
    actions->set("Select Preset",         SELECT_PRESET_ACTION_TYPE);
    actions->set("Control Voltage",       CONTROL_VOLTAGE_ACTION_TYPE);
    actions->set("OSC",                   OSC_ACTION_TYPE);
  }
  return actions;
}

static HashMap<String, int> *zones = NULL;
HashMap<String, int>* getZoneTypes(){
  if(zones == NULL){
    zones = new HashMap<String, int>();
    zones->set("Horizontal Slider",       HORIZONTAL_SLIDER_ZONE_TYPE);
    zones->set("Vertical Slider",         VERTICAL_SLIDER_ZONE_TYPE);
    zones->set("Momentary Button",        MOMENTARY_BUTTON_ZONE_TYPE);
    zones->set("Toggle Button",           TOGGLE_BUTTON_ZONE_TYPE);
  }
  return zones;
}

static HashMap<String, int> *displays = NULL;
HashMap<String, int>* getDisplayTypes(){
  if(displays == NULL){
    displays = new HashMap<String, int>();
    displays->set("Fill",                 FILL_DISPLAY_TYPE);
    displays->set("Bar",                  LINE_DISPLAY_TYPE);
    displays->set("Graded Fill",          GRADED_FILL_DISPLAY_TYPE);
    displays->set("Graded Bar",           GRADED_LINE_DISPLAY_TYPE);
  }
  return displays;
}

PresetFactory::PresetFactory(){
}

void PresetFactory::loadPreset(Preset& preset, File& file){
  PropertiesFile props(file, PropertiesFile::Options());
  PropertySet set;
  if(props.getIntValue("version") != FILE_FORMAT_VERSION){
    std::cout << "incompatible preset format " << props.getFile().getFullPathName()
	      << ": " << props.getIntValue("version") << std::endl;
    return;
  }
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    String zn("zone");
    zn += i;
    ScopedPointer<XmlElement> xml;
    xml = props.getXmlValue(zn);
    if(xml){
      set.restoreFromXml(*xml);
      Zone* zone = loadZone(set);
      preset.setZone(i, zone);
    }
  }
  std::cout << "loaded preset from file " << props.getFile().getFullPathName() << std::endl;
}

Zone* PresetFactory::loadZone(PropertySet& set){
  Zone* zone = createZone(set.getValue("type"));
  if(zone == NULL)
    return NULL;
  zone->setDisplayType((DisplayType)getDisplayTypeCode(set.getValue("display")));
  zone->from.setColumn(set.getIntValue("from_column"));
  zone->to.setColumn(set.getIntValue("to_column"));
  zone->from.setRow(set.getIntValue("from_row"));
  zone->to.setRow(set.getIntValue("to_row"));
  zone->action = loadAction(set);
  return zone;
}

Action* PresetFactory::loadAction(PropertySet& set){
  Action* action = createAction(set.getValue("action"));
  if(action == NULL)
    return NULL;
  uint8_t data[8];
  memset(data, 0, sizeof(data));
  data[3] = set.getIntValue("status");;
  data[4] = set.getIntValue("min");
  data[5] = set.getIntValue("max");
  data[6] = set.getIntValue("data1");
  data[7] = set.getIntValue("data2");
  action->read(data);
  return action;
}

void PresetFactory::savePreset(Preset& preset, File& file){
  PropertiesFile props(file, PropertiesFile::Options());
  PropertySet set;
//   props.setValue("preset", index);
  props.setValue("version", FILE_FORMAT_VERSION);
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    if(saveZone(preset.getZone(i), set)){
      String zn("zone");
      zn += i;
      ScopedPointer<XmlElement> xml;
      xml = set.createXml("zone");
      props.setValue(zn, xml);
    }
  }
  props.save();
  std::cout << "saved preset " << index << " to file " << props.getFile().getFullPathName() << std::endl;    
}

bool PresetFactory::saveZone(Zone* zone, PropertySet& set){
  if(zone == NULL || zone->getZoneType() == DISABLED_ZONE_TYPE)
    return false;
  set.setValue("type", getZoneTypeName(zone->getZoneType()));
  set.setValue("display", getDisplayTypeName(zone->getDisplayType()));
  set.setValue("from_column", zone->from.getColumn());
  set.setValue("to_column", zone->to.getColumn());
  set.setValue("from_row", zone->from.getRow());
  set.setValue("to_row", zone->to.getRow());
  saveAction(zone->action, set);
  return true;
}

void PresetFactory::saveAction(Action* action, PropertySet& set){
  if(action == NULL)
    return;
  set.setValue("action", getActionTypeName(action->getActionType()));
  uint8_t data[8];
  memset(data, 0, sizeof(data));
  uint8_t sz = action->write(data);
  set.setValue("status", data[3]);
  if(sz > 1)
    set.setValue("min", data[4]);
  if(sz > 2)
    set.setValue("max", data[5]);
  if(sz > 3)
    set.setValue("data1", data[6]);
  if(sz > 4)
    set.setValue("data2", data[7]);
}

String PresetFactory::getDisplayTypeName(uint8_t code){
  HashMap<String, int>* displaytypes = getDisplayTypes();
  for(HashMap<String, int>::Iterator i(*displaytypes); i.next();)
    if(i.getValue() == code)
      return i.getKey();
  return "None";
}

uint8_t PresetFactory::getDisplayTypeCode(String name){
  HashMap<String, int>* displaytypes = getDisplayTypes();
  if(displaytypes->contains(name))
    return (*displaytypes)[name];
  return NONE_DISPLAY_TYPE;
}

String PresetFactory::getZoneTypeName(uint8_t code){
  HashMap<String, int>* zones = getZoneTypes();
  for(HashMap<String, int>::Iterator i(*zones); i.next();)
    if(i.getValue() == code)
      return i.getKey();
  return "Disabled Zone";
}

uint8_t PresetFactory::getZoneTypeCode(String name){
  HashMap<String, int>* zones = getZoneTypes();
  if(zones->contains(name))
    return (*zones)[name];
  return DISABLED_ZONE_TYPE;
}

Zone* PresetFactory::createZone(String name){
  return createZone(getZoneTypeCode(name));
}

Zone* PresetFactory::createZone(uint8_t type){
  return Zone::createZone(type);
}

String PresetFactory::getActionTypeName(uint8_t code){
  HashMap<String, int>* actions = getActionTypes();
  for(HashMap<String, int>::Iterator i(*actions); i.next();)
    if(i.getValue() == code)
      return i.getKey();
  return "No Action";
}

uint8_t PresetFactory::getActionTypeCode(String name){
  HashMap<String, int>* actions = getActionTypes();
  if(actions->contains(name))
    return (*actions)[name];
  return NO_ACTION_TYPE;
}

Action* PresetFactory::createAction(String name){
  return createAction(getActionTypeCode(name));
}

Action* PresetFactory::createAction(uint8_t type){
  Action* action = NULL;
  if(type == OSC_ACTION_TYPE)
    action = new OscAction();
  else
    action = Action::createAction(type);
  return action;
}
