
#include "PresetFactory.h"

#include "defs.h"
#include <inttypes.h>
#include <string.h>


#define FILE_FORMAT_VERSION 2

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
      Zone& zone = *preset.getZone(i);
      delete zone.action;
      loadZone(zone, set);
    }
  }
  std::cout << "loaded preset from file " << props.getFile().getFullPathName() << std::endl;
}

void PresetFactory::loadZone(Zone& zone, PropertySet& set){
  zone.setZoneType(set.getIntValue("type"));
  zone.setDisplayType(set.getIntValue("display"));
  zone.from.setColumn(set.getIntValue("from_column"));
  zone.to.setColumn(set.getIntValue("to_column"));
  zone.from.setRow(set.getIntValue("from_row"));
  zone.to.setRow(set.getIntValue("to_row"));
  zone.action = loadAction(set);
}

Action* PresetFactory::loadAction(PropertySet& set){
  uint8_t status = set.getIntValue("status");
  Action* action = Action::createAction(status);
  if(action == NULL)
    return NULL;
  uint8_t data[8];
  memset(data, 0, sizeof(data));
  data[3] = status;
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
  props.setValue("preset", index);
  props.setValue("version", FILE_FORMAT_VERSION);
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    saveZone(preset.getZone(i), set);
    String zn("zone");
    zn += i;
    ScopedPointer<XmlElement> xml;
    xml = set.createXml("zone");
    props.setValue(zn, xml);
  }
  props.save();
  std::cout << "saved preset " << index << " to file " << props.getFile().getFullPathName() << std::endl;    
}

void PresetFactory::saveZone(Zone* zone, PropertySet& set){
  if(zone == NULL)
    return;
  //       set.setValue("index", i);
  set.setValue("type", zone->getZoneType());
  set.setValue("display", zone->getDisplayType());
  set.setValue("from_column", zone->from.getColumn());
  set.setValue("to_column", zone->to.getColumn());
  set.setValue("from_row", zone->from.getRow());
  set.setValue("to_row", zone->to.getRow());
  saveAction(zone->action, set);
}

void PresetFactory::saveAction(Action* action, PropertySet& set){
  if(action == NULL)
    return;
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
