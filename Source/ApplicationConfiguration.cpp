#include "ApplicationConfiguration.h"

MidiOutput* midiout = NULL;

MidiOutput* ApplicationConfiguration::getMidiOutput(){
  if(midiout == NULL){
    midiout = MidiOutput::createNewDevice(T("BlipZones"));
    //       midiout = MidiOutput::openDevice(MidiOutput::getDefaultDeviceIndex());
  }
  return midiout;
}

void ApplicationConfiguration::setMidiOutput(MidiOutput* midi){
  midiout = midi;
}

BlipSim* blipsim = NULL;
BlipSim* ApplicationConfiguration::getBlipSim(){
  if(blipsim == NULL)
    blipsim = new BlipSim();
  return blipsim;
}

BlipClient* blipclient = NULL;
BlipClient* ApplicationConfiguration::getBlipClient(){
  if(blipclient == NULL)
    blipclient = new BlipClient();
  return blipclient;
}

SimScreen* simwindow = NULL;
SimScreen* ApplicationConfiguration::getSimScreen(){
  return simwindow;
}

void ApplicationConfiguration::setSimScreen(SimScreen* window){
  simwindow = window;
}

MidiZonePreset presets[MIDI_ZONE_PRESETS];
MidiZonePreset* ApplicationConfiguration::getMidiZonePreset(int index){
  return &presets[index];
}

void ApplicationConfiguration::initialise(){
  for(int i=0; i<MIDI_ZONE_PRESETS; ++i)
    presets[i].setIndex(i);
}

void ApplicationConfiguration::release(){
/*     If you're leaking, it's probably because you're using old-fashioned, non-RAII techniques for */
/*     your object management. Tut, tut. Always, always use ScopedPointers, OwnedArrays, */
/*     ReferenceCountedObjects, etc, and avoid the 'delete' operator at all costs! */
  deleteAndZero(midiout);
  deleteAndZero(blipsim);
  deleteAndZero(blipclient);
  simwindow = NULL;
}
