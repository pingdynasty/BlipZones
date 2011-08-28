#ifndef __OVERFLOWTIMER_H__
#define __OVERFLOWTIMER_H__

#include "../JuceLibraryCode/JuceHeader.h"

extern "C" void SIG_OVERFLOW0();
unsigned long millis(void);

#define CALIBRATION_INTERVAL 10000 // calibrate OverflowTimer every so often (milliseconds)
#define CALIBRATION_TOLERANCE 0.10 // drift tolerance over calibration interval (percent/100)

class OverflowTimer : public Thread { 
// juce::Timer can't do 1ms accuracy
public:
  OverflowTimer(double periodSeconds) : Thread(T("Overflow Timer")) {
    period = Time::secondsToHighResolutionTicks(periodSeconds);
    std::cout << "period " << period << " ticks" << std::endl;
    setPriority(0);
  }
  void run(){
    while(!threadShouldExit()){
      sleep(1);
      SIG_OVERFLOW0();
    }
  }
  void runHighRes(){
    int64 timerms = millis();
    int64 ticks = Time::getHighResolutionTicks();
    int64 lastcalibrated = Time::currentTimeMillis();
    int64 calibrationperiod = CALIBRATION_INTERVAL;
    while(!threadShouldExit()){
      if(Time::getHighResolutionTicks() - ticks > period){
	ticks = Time::getHighResolutionTicks();
	SIG_OVERFLOW0();
      }
      if(Time::currentTimeMillis() - lastcalibrated > calibrationperiod){
	double drift = 1.0 - (double)(millis() - timerms) / (Time::currentTimeMillis() - lastcalibrated);
	if(std::abs(drift) > CALIBRATION_TOLERANCE){
	  period -= period*drift/2.0;
	  std::cout << "ms  " << (Time::currentTimeMillis() - lastcalibrated) << " \t" << (millis() - timerms) << " \t drift: " << drift*100.0 << "%\t adjusted period: " << period << std::endl;
	}
	timerms = millis();
	lastcalibrated = Time::currentTimeMillis();
      }
      yield();
    }
  }
private:
  int64 period;
};

#endif  // __OVERFLOWTIMER_H__
