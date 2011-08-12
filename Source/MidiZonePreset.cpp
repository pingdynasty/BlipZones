#include "MidiZonePreset.h"
#include "globals.h"
#include "ApplicationConfiguration.h"

MidiZonePreset::MidiZonePreset(){
  reset();
  uint8_t channel = 0;

  zones[0]._to_column = 10;
  zones[0]._to_row = 8;
  zones[0]._type = MIDI_ZONE_TYPE | HORIZONTAL_VERTICAL_ZONE_BIT | BAR_DISPLAY_TYPE;
  zones[0]._status = MIDI_CONTROL_CHANGE | channel;
  zones[0]._min = 0;
  zones[0]._max = 127;
  zones[0]._data1 = 40;

  zones[1]._to_column = 10;
  zones[1]._to_row = 8;
  zones[1]._type = MIDI_ZONE_TYPE | BAR_DISPLAY_TYPE;
  zones[1]._status = MIDI_CONTROL_CHANGE | channel;
  zones[1]._min = 0;
  zones[1]._max = 127;
  zones[1]._data1 = 41;

  selected = -1;
}

void MidiZonePreset::reset(){
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    zones[i]._type = MIDI_ZONE_TYPE | HORIZONTAL_VERTICAL_ZONE_BIT | NO_DISPLAY_TYPE;
    //       zones[i]._type = EMPTY_ZONE_TYPE;
    zones[i]._status = MIDI_CONTROL_CHANGE;
    zones[i]._data1 = 0;
    zones[i]._data2 = 0;
    zones[i]._min = 0;
    zones[i]._max = 127;
    zones[i]._from_column = 0;
    zones[i]._to_column = 0;
    zones[i]._from_row = 0;
    zones[i]._to_row = 0;
  }
}

void MidiZonePreset::start(){
  blipbox.eventhandler = this;
  blipbox.animator = this;
}

void MidiZonePreset::stop(){
  blipbox.animator = NULL;
  blipbox.eventhandler = &blipbox.defaulthandler;
}

uint8_t MidiZonePreset::getIndex(){
  return preset;
}

void MidiZonePreset::setIndex(uint8_t _index){
  preset = _index;
}

MidiZone* MidiZonePreset::getZone(uint8_t index){
  return &zones[index];
}

MidiZone* MidiZonePreset::getSelectedZone(){
  if(selected < 0 || selected >= sizeof(zones))
    return NULL;
  return &zones[selected];
}

uint8_t MidiZonePreset::getSelectedZoneIndex(){
  return selected+1;
}

void MidiZonePreset::selectZone(uint8_t index){
  if(index > 0 && index <= MIDI_ZONES_IN_PRESET)
    selected = index-1;
  else
    selected = -1;
}

void MidiZonePreset::taptap(Position& pos){
  std::cout << "taptap [" << (int)pos.column << "][" << (int)pos.row << "]" << std::endl;
//   MidiZoneEventHandler::taptap(pos);
}

void MidiZonePreset::read(const uint8_t* data){
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i)
    zones[i].read(&data[i*MIDI_ZONE_PRESET_SIZE]);
}

void MidiZonePreset::saveFile(const File& file){
//   File file(ApplicationConfiguration::getDefaultPresetPath());
  PropertiesFile props(file, PropertiesFile::Options());
  PropertySet set;
  props.setValue("preset", preset);
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    //       set.setValue("index", i);
    set.setValue("type", zones[i]._type);
    set.setValue("status", zones[i]._status);
    set.setValue("data1", zones[i]._data1);
    set.setValue("min", zones[i]._min);
    set.setValue("max", zones[i]._max);
    set.setValue("from_column", zones[i]._from_column);
    set.setValue("to_column", zones[i]._to_column);
    set.setValue("from_row", zones[i]._from_row);
    set.setValue("to_row", zones[i]._to_row);
    String zn("zone");
    zn += i;
    ScopedPointer<XmlElement> xml;
    xml = set.createXml("zone");
    props.setValue(zn, xml);
  }
  props.save();
  std::cout << "saved preset " << preset << " to file " << props.getFile().getFullPathName() << std::endl;
}

void MidiZonePreset::loadFile(const File& file){
//   File file(ApplicationConfiguration::getDefaultPresetPath());
  PropertiesFile props(file, PropertiesFile::Options());
  PropertySet set;
  //     props.getValue("preset");
  for(uint8_t i=0; i<MIDI_ZONES_IN_PRESET; ++i){
    String zn("zone");
    zn += i;
    ScopedPointer<XmlElement> xml;
    xml = props.getXmlValue(zn);
    if(xml){
      set.restoreFromXml(*xml);
      zones[i]._type = set.getIntValue("type");
      zones[i]._status = set.getIntValue("status");
      zones[i]._data1 = set.getIntValue("data1");
      zones[i]._min = set.getIntValue("min");
      zones[i]._max = set.getIntValue("max");
      zones[i]._from_column = set.getIntValue("from_column");
      zones[i]._to_column = set.getIntValue("to_column");
      zones[i]._from_row = set.getIntValue("from_row");
      zones[i]._to_row = set.getIntValue("to_row");
    }
  }
  std::cout << "loaded preset " << preset << " from file " << props.getFile().getFullPathName() << std::endl;
}

void MidiZonePreset::tick(uint16_t counter){
  if(selected == -1){
    MidiZoneEventHandler::tick(counter);
  }else{
    blipbox.leds.clear();
    MidiZone* zone = &zones[selected];
    for(int x=std::min(zone->_from_column, zone->_to_column); x<std::max(zone->_from_column, zone->_to_column); ++x)
      for(int y=std::min(zone->_from_row, zone->_to_row); y<std::max(zone->_from_row, zone->_to_row); ++y)
	blipbox.leds.setLed(x, y, 0x80);
    blipbox.leds.flip();
  }
}
