#ifndef __ASIOSERIAL_H__
#define __ASIOSERIAL_H__

#include "Serial.h"
/* #include <boost/asio.hpp> */

class AsioSerial : public Serial {
private:
/*   boost::asio::io_service io_service; */

public:
 AsioSerial(const juce::String& port, int speed, bool verbose = true)
   : Serial(port, speed, verbose){
  }
 AsioSerial()
   : Serial(){
  }
  int connect();
  int disconnect();
  bool isConnected();
  ssize_t readSerial(unsigned char* data, ssize_t len);
  ssize_t writeSerial(unsigned char* data, ssize_t len);
};

#endif  // __ASIOSERIAL_H__
