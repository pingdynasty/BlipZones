#ifndef __BLIPCLIENT_H__
#define __BLIPCLIENT_H__

#include <stdint.h>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Serial.h"
#include "Zone.h"
#include "Command.h"

class BlipClient : public SerialCallback, public juce::Thread {
public:
  BlipClient();
  ~BlipClient();
/*   void initialise(); */
  int connect();
  int disconnect();
  void shutdown();
  int handle(unsigned char* data, size_t len);
  void handleReleaseMessage();
  void handlePositionMessage(uint16_t x, uint16_t y);
  void handleParameterMessage(uint8_t pid, uint16_t value);
  void sendScreenUpdates(bool send);
  bool isConnected();
  void run();
  void setPort(const juce::String& aport);
  void setSpeed(int aspeed);
  void clear();
  void fill(uint8_t value);
  void setLed(uint8_t x, uint8_t y, uint8_t brightness);
  void requestPreset(uint8_t index);
  void sendPreset(uint8_t index);
  void drawZone(Zone* zone);
  void sendCommand(Command command);
  void sendParameter(uint8_t pid, uint16_t value);
  void sendSerial(uint8_t* data, size_t size);
  uint16_t getControlVoltage(uint8_t channel);
  void setControlVoltage(uint8_t channel, uint16_t value);
private:
  uint16_t controlvoltages[4];
  Serial *serial;
};

#endif  // __BLIPCLIENT_H__
