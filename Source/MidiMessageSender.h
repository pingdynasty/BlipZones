#ifndef __MIDIMESSAGESENDER_H__
#define __MIDIMESSAGESENDER_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "ApplicationConfiguration.h"

#define MIDI_NOTE_OFF                 0x80
#define MIDI_NOTE_ON                  0x90
#define MIDI_AFTERTOUCH               0xA0
#define MIDI_CONTROL_CHANGE           0xB0
#define MIDI_PROGRAM_CHANGE           0xC0
#define MIDI_CHANNEL_PRESSURE         0xD0
#define MIDI_PITCH_BEND               0xE0
#define MIDI_SYSTEM_MESSAGE           0xF0

#define MIDI_MESSAGE_SENDER_BUFFER_LENGTH 512

class MidiMessageSender {
 public:
 MidiMessageSender() : frompos(1), topos(0), len(0), midiout(NULL) {
  };

  ~MidiMessageSender(){
    if(midiout != NULL)
      delete midiout;
  }

  void setMidiOutput(juce::String name){
    std::cout << "setting midi output: " << name << std::endl;
    if(MidiOutput::getDevices().contains(name)){
      setMidiOutput(MidiOutput::openDevice(MidiOutput::getDevices().indexOf(name)));
#if ! JUCE_WINDOWS
    }else if(name.compare("BlipZones") == 0){
      setMidiOutput(MidiOutput::createNewDevice(T("BlipZones")));
#endif
    }else{
      setMidiOutput(NULL);
    }
  }

  void setMidiOutput(juce::MidiOutput* output){
    if(midiout != NULL)
      delete midiout;
    midiout = output;
  }

  void handleByte(uint8_t bt){
    buf[topos++] = bt;
    len = topos-frompos;
    if(len > 0)
      process();
  }

  void process(){
    uint8_t msglen = 0;
    switch(buf[frompos] & 0xf0){
    case MIDI_NOTE_OFF:
    case MIDI_NOTE_ON:
    case MIDI_CONTROL_CHANGE:
    case MIDI_PROGRAM_CHANGE:
    case MIDI_AFTERTOUCH:
    case MIDI_PITCH_BEND:
      msglen = 3;
      break;
    case MIDI_CHANNEL_PRESSURE:
      msglen = 2;
      break;
    case MIDI_SYSTEM_MESSAGE:
      if(buf[frompos] != 0xf0 && buf[frompos] != 0xff){
	msglen = 1;
	break;
      }
      // conditional fall-through
    default:
      std::cout << "invalid midi message: 0x" << std::hex << (int)buf[frompos] << std::endl;
      len = topos - ++frompos;
      if(len <= 0)
	topos = frompos = len = 0;
      return;
    }
    std::cout << "midi message: " << (int)msglen << " / " << (int)len << std::endl;
    if(msglen > 0 && msglen <= len){
      int used;
      msg = juce::MidiMessage(&buf[frompos], msglen, used, msg.getRawData()[0]);
      if(midiout != NULL)
	midiout->sendMessageNow(msg);
/*       if(m_verbose) */
/* 	std::cout << "rx" << print(msg) << std::endl; */
      // 	std::cout << "rx:" << frompos << "-" << topos << " " << used << "/" << len << std::endl;
      if(used == len)
	frompos = topos = 0;
      else
	frompos += used;
      len = topos-frompos;
      if(topos >= MIDI_MESSAGE_SENDER_BUFFER_LENGTH){
	std::cerr << "buffer overflow!" << std::endl;
	frompos = topos = len = 0;
      }else if(len > 0){
	process();
      }
    }
  }
 private:
  juce::MidiMessage msg;
  juce::MidiOutput* midiout;
  ssize_t len;
  unsigned char buf[MIDI_MESSAGE_SENDER_BUFFER_LENGTH];
  int frompos;
  int topos;
};

#endif  // __MIDIMESSAGESENDER_H__
