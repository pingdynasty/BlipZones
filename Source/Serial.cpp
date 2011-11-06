#include "Serial.h"

#define SERIAL_BUFFER_LENGTH 2048

Serial::Serial(const juce::String& aport, int aspeed, bool averbose)
  : port(aport), speed(aspeed), verbose(averbose), 
    callback(NULL), connected(false), running(false) {
}

Serial::Serial() :
  port(), speed(-1), verbose(false),
  callback(NULL), connected(false), running(false) {
}

Serial::~Serial(){
}

juce::String& Serial::getPort(){
  return port;
}

void Serial::setPort(const juce::String& aport){
  port = aport;
}

int Serial::getSpeed(){
  return speed;
}

void Serial::setSpeed(int aspeed){
  speed = aspeed;
}

void Serial::setSerialCallback(SerialCallback* cb){
  callback = cb;
}

void Serial::stop(){
  running = false;
}

void Serial::start(){
  running = true;
}

bool Serial::isConnected(){
  return connected;
}

void Serial::run(){
  size_t len;
  unsigned char buf[SERIAL_BUFFER_LENGTH];
  int used = 0;
  int frompos = 0;
  int topos = 0;

  if(verbose)
    std::cout << "starting rx" << std::endl;

  while(running) {
    len = readSerial(&buf[topos], SERIAL_BUFFER_LENGTH-topos);
    topos += len;
    len = topos-frompos;
    if(len > 0){
      do{
	if(verbose){
	  std::cout << "rx\t";
	  log(&buf[frompos], len);
	}
	if(callback){
	  used = callback->handle(&buf[frompos], len);
	}else{
	  used = len;
	}
	if(used == len)
	  frompos = topos = 0;
	else
	  frompos += used;
	len = topos-frompos;
      }while(used > 0 && len > 0);
    }
    if(topos >= SERIAL_BUFFER_LENGTH-1){
      std::cerr << "buffer overflow!" << std::endl;
      frompos = topos = 0;
    }
  }

  if(verbose)
    std::cout << "stopping rx" << std::endl;
}
