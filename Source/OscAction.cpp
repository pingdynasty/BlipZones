#include "OscAction.h"
#include "OscServer.h"

static OscServer server;

void OscAction::sendMessage(float value){
  std::cout << prefix << value << suffix << std::endl;
  server.send(this);
}
