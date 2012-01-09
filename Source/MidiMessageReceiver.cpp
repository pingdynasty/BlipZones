#include "MidiMessageReceiver.h"

#include "ApplicationConfiguration.h"
#include "BlipSim.h"
#include "Event.h"
#include "Preset.h"

void MidiMessageReceiver::handleIncomingMidiMessage(MidiInput* source, const MidiMessage& msg){
  std::cout << "midi! " << msg.getRawDataSize() << std::endl;
//   ControlValues* values = ApplicationConfiguration::getControlValues();
  if(msg.getRawDataSize() == 3){
    MidiEvent event(msg.getRawData()[0], msg.getRawData()[1], msg.getRawData()[2]);
//     ApplicationConfiguration::getBlipSim()->handle(event);
    ApplicationConfiguration::getPreset(ApplicationConfiguration::getBlipSim()->getPresetIndex())->
      handle(event);
  }
//   if(msg.isNoteOnOrOff()){
//     values->setNote(msg.getChannel()-1, msg.getNoteNumber(), msg.isNoteOn() ? msg.getVelocity() : 0);
//   }else if(msg.isController()){
//     values->setController(msg.getChannel()-1, msg.getControllerNumber(), msg.getControllerValue());
//   }else if(msg.isProgramChange()){
//     // todo!
//   }else if(msg.isPitchWheel()){
//     // todo!
//   }else if(msg.isChannelPressure()){
//     // todo!
//   }else if(msg.isAftertouch()){
//     // todo!
//   }else if(msg.isAllNotesOff()){
//     // todo!
//   }else if(msg.isAllSoundOff()){
//     // todo!
//   }
}

/* void MidiInputCallback::handlePartialSysexMessage(MidiInput *source, */
/* 						  const uint8* messageData, */
/* 						  const int numBytesSoFar,  */
/* 						  const double timestamp){ */
/* } */
