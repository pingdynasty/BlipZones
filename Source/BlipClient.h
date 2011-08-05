#ifndef __BLIPBOX_H__
#define __BLIPBOX_H__

#include <sys/types.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>

#include "../JuceLibraryCode/JuceHeader.h"
#include "Serial.h"
#include "MidiZone.h"
#include "PresetComponent.h"

#define FILL_MESSAGE              0x10
#define SET_LED_MESSAGE           0x20 // sets 1 led - 3 byte message
// set led: 4 bits marker type, 8 bits led index, 8 bits brightness
// 1000mmmm llllllll bbbbbbbb
#define SET_LED_ROW_MESSAGE       0x30 // sets 8 leds - two byte message
// led row: 0011cccc bbbbbbbb : 4 bit row index i, bit mask b
#define SET_LED_COL_MESSAGE       0x40 // sets 8 leds - two byte message
// led column: 0100iiii bbbbbbbb : 4 bit column index i, bit mask b
#define WRITE_CHARACTER_MESSAGE   0x50
#define SHIFT_LEDS_MESSAGE        0x60
#define COMMAND_MESSAGE           0x70
// command: 0111cccc : 4 bit command index
#define SET_PARAMETER_MESSAGE     0xc0

class BlipClient : public Serial, public juce::Thread {
public:
/*   BlipClient(const juce::String& port, int speed, bool verbose = true) */
/*     : Serial(port, speed, verbose), */
/*       Thread(T("BlipClient")) */
/*   {} */
  int connect(){
    std::cout << "starting blipbox serial connection on " << getPort() << std::endl;
    int status = Serial::connect();
    Serial::start();
    juce::Thread::startThread();
    return status;
  }
  int disconnect(){
    Serial::stop();
    std::cout << "stopping blipbox serial connection on " << getPort() << std::endl;
    juce::Thread::stopThread(30000); // 30 secs
    return Serial::disconnect();
  }
  void run(){
    Serial::run();
  }
  int handle(unsigned char* data, ssize_t len);
  void handleReleaseMessage();
  void handlePositionMessage(uint16_t x, uint16_t y);
  void handleParameterMessage(uint8_t pid, uint16_t value);
/* }; */

/* class BlipClient { */
private:
/*   BlipClientSerial* serial; */
  MidiZonePreset presets[MIDI_ZONE_PRESETS];
  Serial *serial;
public:

  BlipClient(const juce::String& port, int speed = 57600, bool verbose = false)
    : Serial(port, speed, verbose),
      Thread(T("BlipClient"))
  {
    for(int i=0; i<MIDI_ZONE_PRESETS; ++i)
      presets[i].preset = i;
    serial = this;
  }
  PresetComponent* handler;
  void setEventHandler(PresetComponent* ahandler){
    handler = ahandler;
  }
/*   void connect(){ */
/*     serial = new BlipClientSerial(L"/dev/tty.usbserial-A60081hf", 57600); */
/*     serial->connect(); */
/*   } */

/*   void disconnect(){ */
/*     if(serial != NULL) */
/*       serial->disconnect(); */
/*     delete serial; */
/*   } */

  void clear(){
    fill(0);
  }

  void fill(uint8_t value);
  void setLed(uint8_t x, uint8_t y, uint8_t brightness);

  void requestMidiZonePreset(uint8_t index);
  void sendMidiZonePreset(MidiZonePreset& preset);
  void drawMidiZone(MidiZone& zone);
  MidiZonePreset* getPreset(uint8_t index){
    if(index < MIDI_ZONE_PRESETS)
      return &presets[index];
    return NULL;
  }      
};

#endif  // __BLIPBOX_H__
