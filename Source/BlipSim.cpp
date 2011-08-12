#include "BlipSim.h"
#include "globals.h"
#include "OverflowTimer.h"

#define THREAD_TIMEOUT_MS 2000

class BlipBoxThread : public Thread { 
public:
  BlipBoxThread() : Thread(T("BlipBox Simulator")) {}
  void run(){
    while(!threadShouldExit()){
      loop();
      yield();
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
  blipthread = new BlipBoxThread();
  timer0 = new OverflowTimer(0.001);
}

void BlipSim::start(){
  blipthread->startThread();
  timer0->startThread();
  std::cout << "started threads" << std::endl;
}

void BlipSim::stop(){
  blipthread->stopThread(THREAD_TIMEOUT_MS);
  timer0->stopThread(THREAD_TIMEOUT_MS);
  std::cout << "stopped threads" << std::endl;
}

void BlipSim::shutdown(){
  stop();
  deleteAndZero(timer0);
  deleteAndZero(blipthread);
}

extern "C" void SIG_USART_RECV();
extern "C" uint8_t UDR0;

void BlipSim::sendSerial(uint8_t* data, ssize_t size){
  for(int i=0; i<size; ++i){
    UDR0 = data[i];
    SIG_USART_RECV();    
  }
}

#include "MidiMessageSender.h"

MidiMessageSender midi;

extern "C" {

  // simulator callbacks
  uint8_t domidi;
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
