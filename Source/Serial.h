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
  Serial(const juce::String& aport, int aspeed, bool averbose = false)
    : port(aport), speed(aspeed), verbose(averbose), 
      callback(NULL), connected(false), running(false) {
  }
   Serial() :
   port(NULL), speed(-1), verbose(false),
   callback(NULL), connected(false), running(false) {
  }
  virtual ~Serial(){
  }
  juce::String& getPort(){
    return port;
  }
  void setPort(const juce::String& aport){
    port = aport;
  }
  int getSpeed(){
    return speed;
  }
  void setSpeed(int aspeed){
    speed = aspeed;
  }
  void setSerialCallback(SerialCallback* cb){
    callback = cb;
  }
  virtual void stop(){
    running = false;
  }
  virtual void start(){
    running = true;
  }
  virtual bool isConnected(){
    return connected;
  }
  virtual int connect() = 0;
  virtual int disconnect() = 0;
  virtual bool checkConnection() = 0;
  virtual int openSerial(const char* serialport, int baud) = 0;
  virtual ssize_t readSerial(unsigned char* data, ssize_t len) = 0;
  virtual ssize_t writeSerial(unsigned char* data, ssize_t len) = 0;
  virtual void run() = 0;

  static Serial* createSerial();
protected:
  virtual void log(unsigned char* data, ssize_t len){
    for(int i=0; i<len; ++i)
      std::cout << "0x" << std::hex << (int)data[i] << "\t";
    std::cout << std::endl;
  }
};

#endif  // __SERIAL_H__
