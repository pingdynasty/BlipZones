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
    close();
  }

  void close(){
    if(midiin != NULL){
      midiin->stop();
      delete midiin;
    }
  }

  void setMidiInput(juce::String name){
    std::cout << "setting midi input: " << name << std::endl;
    if(MidiInput::getDevices().contains(name)){
      setMidiInput(MidiInput::openDevice(MidiInput::getDevices().indexOf(name), this));
#if ! JUCE_WINDOWS
    }else if(name.compare("BlipZones") == 0){
      setMidiInput(MidiInput::createNewDevice(T("BlipZones"), this));
#endif
    }else{
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
