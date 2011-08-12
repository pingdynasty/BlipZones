#ifndef __BLIPCLIENT_H__
#define __BLIPCLIENT_H__

#include <sys/types.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>

#include "../JuceLibraryCode/JuceHeader.h"
#include "Serial.h"
#include "MidiZone.h"
#include "Command.h"

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

#define DEFAULT_SERIAL_PORT       L"/dev/tty.usbserial"

class BlipClient : public Serial, public juce::Thread {
public:
  int connect();
  int disconnect();
  void shutdown(){
    stop();
    disconnect();
  }
  void run(){
    Serial::run();
  }
  int handle(unsigned char* data, ssize_t len);
  void handleReleaseMessage();
  void handlePositionMessage(uint16_t x, uint16_t y);
  void handleParameterMessage(uint8_t pid, uint16_t value);

private:
  Serial *serial;

public:
  BlipClient(const juce::String& port = DEFAULT_SERIAL_PORT, int speed = 57600, bool verbose = false)
    : Serial(port, speed, verbose),
      Thread(T("BlipClient"))
  {
    serial = this;
  }

  void clear(){
    fill(0);
  }

  void fill(uint8_t value);
  void setLed(uint8_t x, uint8_t y, uint8_t brightness);
  void requestMidiZonePreset(uint8_t index);
  void sendMidiZonePreset(uint8_t index);
  void drawMidiZone(MidiZone* zone);
  void sendCommand(Command command);
  void sendSerial(uint8_t* data, ssize_t size);
};

#endif  // __BLIPCLIENT_H__
