#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <sys/types.h>
#include "../JuceLibraryCode/JuceHeader.h"

class SerialCallback {
public:
  virtual ~SerialCallback(){}
  virtual int handle(unsigned char* data, ssize_t len) = 0;
};

class Serial {
protected:
  SerialCallback* callback;
  juce::String port;
  int speed;
  bool verbose;
  volatile bool connected;
  volatile bool running;

public:
  Serial();
  Serial(const juce::String& aport, int aspeed, bool averbose = false);
  virtual ~Serial();
  juce::String& getPort();
  void setPort(const juce::String& aport);
  int getSpeed();
  void setSpeed(int aspeed);
  void setSerialCallback(SerialCallback* cb);
  virtual void stop();
  virtual void start();
  virtual bool isConnected();
  virtual void run();
  virtual int connect() = 0;
  virtual int disconnect() = 0;
  virtual ssize_t readSerial(unsigned char* data, ssize_t len) = 0;
  virtual ssize_t writeSerial(unsigned char* data, ssize_t len) = 0;

  static Serial* createSerial();
protected:
  virtual void log(unsigned char* data, ssize_t len){
    for(int i=0; i<len; ++i)
      std::cout << "0x" << std::hex << (int)data[i] << "\t";
    std::cout << std::endl;
  }
};

#endif  // __SERIAL_H__
