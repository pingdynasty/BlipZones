#ifndef _OSC_ACTION_H_
#define _OSC_ACTION_H_

#define OSC_ACTION_TYPE          0x60

#include "Action.h"
#include "../JuceLibraryCode/JuceHeader.h"

class OscAction : public Action {
public:
  String prefix;
  String suffix;
  float minimum;
  float maximum;
  float value;
  OscAction() : minimum(0), maximum(1), value(0) {}
  uint8_t read(const uint8_t* data){
    return 1;
  }
  uint8_t write(uint8_t* data){
    data[3] = getActionType();
    return 1;
  }
  void on(float data){
    data = (data*(maximum-minimum))+minimum;
    if(value != data){
      value = data;
      sendMessage(data);
    }
  }
//   virtual void off(){
//     on(minimum);
//   }
  float getValue() { return (value-minimum)/(maximum-minimum); }
  uint8_t getActionType() { return OSC_ACTION_TYPE; }
  void handle(MidiEvent& event) {}
protected:
  void sendMessage(float value);
};

#endif /* _OSC_ACTION_H_ */

