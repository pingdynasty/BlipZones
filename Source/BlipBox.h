#ifndef __BLIPBOX_H__
#define __BLIPBOX_H__

#include <sys/types.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>

#include "juce.h"
#include "Serial.h"
#include "MidiZone.h"

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

class BlipBoxSerial : public Serial, public juce::Thread {
public:
  BlipBoxSerial(const juce::String& port, int speed, bool verbose = true)
    : Serial(port, speed, verbose),
      Thread(T("BlipBoxSerial"))
  {}
  int connect(){
    std::cout << "starting blipbox serial connection on " << getPort().toUTF8() << std::endl;
    int status = Serial::connect();
    Serial::start();
    juce::Thread::startThread();
    return status;
  }
  int disconnect(){
    Serial::stop();
    std::cout << "stopping blipbox serial connection on " << getPort().toUTF8() << std::endl;
    juce::Thread::stopThread(30000); // 30 secs
    return Serial::disconnect();
  }
  void run(){
    Serial::run();
  }
  int handle(unsigned char* data, ssize_t len);
};

class BlipBox {
private:
  BlipBoxSerial* serial;

public:

  BlipBox() :
    serial(NULL)
  {}

  void connect(){
    serial = new BlipBoxSerial(L"/dev/tty.usbserial-A60081hf", 57600);
    serial->connect();
  }

  void disconnect(){
    if(serial != NULL)
      serial->disconnect();
    delete serial;
  }

  void clear(){
    fill(0);
  }

  void fill(uint8_t value);
  void setLed(uint8_t x, uint8_t y, uint8_t brightness);
  void sendMidiZonePreset(MidiZonePreset& preset);
  void drawMidiZone(MidiZone& zone);
};

#endif  // __BLIPBOX_H__
