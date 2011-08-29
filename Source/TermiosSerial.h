#ifndef __TERMIOSSERIAL_H__
#define __TERMIOSSERIAL_H__

#include "Serial.h"
#include <termios.h>

class TermiosSerial : public Serial {
private:
  int fd;
  struct termios oldtio;

public:
 TermiosSerial()
   : Serial(){
  }
  int connect();
/*   void run(); */
  int openSerial(const char* serialport, int baud);
  size_t readSerial(unsigned char* data, size_t len);
  size_t writeSerial(unsigned char* data, size_t len);
  bool checkConnection();
  bool drain();
  int disconnect();
};

#endif  // __TERMIOSSERIAL_H__
