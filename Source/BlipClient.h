#ifndef __BLIPCLIENT_H__
#define __BLIPCLIENT_H__

#include <stdint.h>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Serial.h"
#include "MidiZone.h"
#include "Command.h"

class BlipClient : public SerialCallback, public juce::Thread {
public:
  void initialise();
  int connect();
  int disconnect();
  void shutdown();
  int handle(unsigned char* data, ssize_t len);
  void handleReleaseMessage();
  void handlePositionMessage(uint16_t x, uint16_t y);
  void handleParameterMessage(uint8_t pid, uint16_t value);
  void sendScreenUpdates(bool send);
  bool isConnected(){
    return serial->isConnected();
  }
  void run(){
    serial->run();
  }
  void setPort(const juce::String& aport){
    serial->setPort(aport);
  }
  void setSpeed(int aspeed){
    serial->setSpeed(aspeed);
  }

private:
  Serial *serial;

public:
  BlipClient();
  ~BlipClient();
  void clear();
  void fill(uint8_t value);
  void setLed(uint8_t x, uint8_t y, uint8_t brightness);
  void requestMidiZonePreset(uint8_t index);
  void sendMidiZonePreset(uint8_t index);
  void drawMidiZone(MidiZone* zone);
  void sendCommand(Command command);
  void sendSerial(uint8_t* data, ssize_t size);
};

#endif  // __BLIPCLIENT_H__
