#ifndef _OSC_SERVER_H_
#define _OSC_SERVER_H_

#include "../JuceLibraryCode/JuceHeader.h"
#define OSC_SERVER_DEFAULT_OUTPUT_BUFFER_SIZE 1024
#define OSC_SERVER_DEFAULT_PORT               7000
#define OSC_SERVER_DEFAULT_HOST               T("localhost")

class OscAction;

class OscServer {
private:
  String hostname;
  int port;
  int bufsize;
public:
  OscServer() :
    hostname(OSC_SERVER_DEFAULT_HOST), 
    port(OSC_SERVER_DEFAULT_PORT), 
    bufsize(OSC_SERVER_DEFAULT_OUTPUT_BUFFER_SIZE) {}

  void configure(String h, int p){
    hostname = h;
    port = p;
  }

//   osc::OutboundPacketStream* getOutputPacketStream(){
//     return new osc::OutboundPacketStream(buffer, OSC_SERVER_OUTPUT_BUFFER_SIZE);
//   }

  void send(OscAction* action);

//   void setHostName(String name){
//     hostname = name;
//   }

};

#endif /* _OSC_SERVER_H_ */

