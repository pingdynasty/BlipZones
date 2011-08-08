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
