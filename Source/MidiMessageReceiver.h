#ifndef __MIDIMESSAGERECEIVER_H__
#define __MIDIMESSAGERECEIVER_H__

#include "../JuceLibraryCode/JuceHeader.h"

class MidiMessageReceiver : public juce::MidiInputCallback {
private:
  juce::MidiInput* midiin;

public:
  MidiMessageReceiver() : midiin(NULL) {
  }

  virtual ~MidiMessageReceiver(){
    delete midiin;
  }

  void close(){
    if(midiin != NULL){
      midiin->stop();
      delete midiin;
      midiin = NULL;
    }
  }

  void setMidiInput(juce::String name){
#if ! JUCE_WINDOWS
    if(name.compare("BlipZones") == 0){
      std::cout << "creating midi input: " << name << std::endl;
      setMidiInput(MidiInput::createNewDevice(name, this));
    }else
#endif
    if(MidiInput::getDevices().contains(name)){
      std::cout << "opening midi input: " << name <<  "." << std::endl;
      setMidiInput(MidiInput::openDevice(MidiInput::getDevices().indexOf(name), this));
    }else{
      std::cout << "no midi input: " << name << std::endl;
      setMidiInput(NULL);
    }
  }

  void setMidiInput(juce::MidiInput* input){
    close();
    midiin = input;
    if(midiin != NULL)
      midiin->start();
  }

/*   virtual void handlePartialSysexMessage(MidiInput* source, const uint8* messageData, */
/* 					 const int numBytesSoFar, const double timestamp); */

  virtual void handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message);
							  
};

#endif  // __MIDIMESSAGERECEIVER_H__
