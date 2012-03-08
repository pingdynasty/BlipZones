#ifndef _OSC_SERVER_H_
#define _OSC_SERVER_H_

#include "../JuceLibraryCode/JuceHeader.h"
#define OSC_SERVER_DEFAULT_OUTPUT_BUFFER_SIZE 1024
#define OSC_SERVER_DEFAULT_PORT               7000
#define OSC_SERVER_DEFAULT_HOST               "localhost"

class OscAction;

class OscServer {
private:
  String hostname;
  int port;
  int bufsize;

public:
  OscServer() :
    hostname(String(OSC_SERVER_DEFAULT_HOST)), 
    port(OSC_SERVER_DEFAULT_PORT), 
    bufsize(OSC_SERVER_DEFAULT_OUTPUT_BUFFER_SIZE) {}

  void setPort(int p){
    port = p;
  }

  void setHostname(String h){
    hostname = h;
  }

  void setBufferSize(int sz){
    bufsize = sz;
  }

  void send(OscAction* action);

};

#endif /* _OSC_SERVER_H_ */

