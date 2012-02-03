#include "OscAction.h"
#include "OscServer.h"
#include "ApplicationConfiguration.h"

uint8_t OscAction::read(const uint8_t* data){
  return 1;
}

uint8_t OscAction::write(uint8_t* data){
  data[3] = getActionType();
  return 1;
}

void OscAction::sendMessage(float value){
  std::cout << prefix << value << std::endl;
  ApplicationConfiguration::getOscServer()->send(this);
}
