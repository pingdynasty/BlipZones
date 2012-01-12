#include "BlipSim.h"
#include "globals.h"
#include "OverflowTimer.h"
#include "MidiMessageSender.h"

#define THREAD_TIMEOUT_MS 2000

MidiMessageSender midi;

class BlipSimThread : public Thread { 
public:
  BlipSimThread() : Thread(T("BlipBox Simulator")) {
    setPriority(0);
  }
  void run(){
    while(!threadShouldExit()){
      loop();
      Thread::sleep(1);
      // todo: sub-ms resolution sleep
//       yield(); // todo: yield doesn't seem to work well on 
    }
  }
};

void BlipSim::initialise(){
  std::cout << "BlipSim::initialise" << std::endl;
  init();
  setup();
  blipbox.config.touchscreen_x_min = 0;
  blipbox.config.touchscreen_y_min = 0;
  blipbox.config.touchscreen_x_range = 1023;
  blipbox.config.touchscreen_y_range = 1023;
  blipthread = new BlipSimThread();
  timer0 = new OverflowTimer(0.001);
}

void BlipSim::start(){
  blipthread->startThread();
  timer0->startThread();
  std::cout << "started threads" << std::endl;
}

void BlipSim::stop(){
  blipbox.animator = NULL;
  blipbox.resetEventHandler();
  midi.setMidiOutput(NULL);
  timer0->stopThread(THREAD_TIMEOUT_MS);
  blipthread->stopThread(THREAD_TIMEOUT_MS);
  std::cout << "stopped threads" << std::endl;
}

void BlipSim::shutdown(){
  stop();
  deleteAndZero(timer0);
  deleteAndZero(blipthread);
}

uint8_t BlipSim::getPresetIndex(){
  return blipbox.config.preset;
}
 
void BlipSim::setPresetIndex(uint8_t index){
  blipbox.config.preset = index;
}

void BlipSim::release(){
  blipbox.keys.setValue(0, 1023);
}

void BlipSim::position(uint16_t x, uint16_t y){
  blipbox.keys.setValue(1, x);
  blipbox.keys.setValue(2, y);
  blipbox.keys.setValue(0, 40);
}

bool BlipSim::isPressed(){
  return blipbox.keys.isPressed();
}

void BlipSim::clear(){
  blipbox.leds.clear();
}

void BlipSim::flip(){
  blipbox.leds.flip();
}

void BlipSim::fill(uint8_t value){
  blipbox.leds.fill(value);
}

void BlipSim::fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t brightness){
  blipbox.display.fill(x1, y1, x2, y2, brightness);
}

void BlipSim::setLed(uint8_t x, uint8_t y, uint8_t brightness){
  if(brightness && brightness < 64)
    brightness = 64; // adjust for non-linear LED brightness
  blipbox.leds.setLed(x, y, brightness);
}

uint8_t BlipSim::getLed(uint8_t x, uint8_t y){
  return blipbox.leds.getLed(x, y);
}

Position& BlipSim::getPosition(){
  return blipbox.keys.pos;
}

extern "C" void USART_RX_vect();
extern "C" uint8_t UDR0;

void BlipSim::sendSerial(uint8_t* data, size_t size){
  for(int i=0; i<size; ++i){
    UDR0 = data[i];
    USART_RX_vect();    
  }
}

// void BlipSim::setMidiOutput(MidiOutput* midiout){
//   midi.setMidiOutput(midiout);
// }

void BlipSim::setMidiOutput(String name){
  midi.setMidiOutput(name);
}

void BlipSim::setAnimator(Animator* animator){
  blipbox.animator = animator;
}

void BlipSim::setEventHandler(EventHandler* handler){
  blipbox.eventhandler = handler;
}

uint8_t domidi;
void BlipSim::doMidi(bool doit){
  domidi = doit;
}

void BlipSim::handle(MidiEvent& event){
  if(domidi)
    blipbox.preset.handle(event);
}

extern "C" {

  // simulator callbacks
  void beginSerial(long baud) {
    printf("sim beginSerial %ld\n", baud);
//     if(baud == 31250)
      domidi = true;
//     else
//       domidi = false;
  }

//   static uint8_t last = 0;
  void serialWrite(unsigned char c) {
//     printf("sim tx 0x%x\n", c);
//     if((last >> 2) == 0x36){
//       uint8_t pid = (last >> 2) & 0x0f;
//       uint16_t value = ((last & 0x3) << 8) | c;
//       ApplicationConfiguration::getBlipClient()->handleParameterMessage(pid, value);
//     }
//     last = c;
    if(domidi){
      midi.handleByte(c);
    }
  }
}
