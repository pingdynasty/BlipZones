#include "OscAction.h"
#include "OscServer.h"
#include "ApplicationConfiguration.h"

void OscAction::sendMessage(float value){
  std::cout << prefix << value << std::endl;
  ApplicationConfiguration::getOscServer()->send(this);
}
