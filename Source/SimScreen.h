#ifndef __SIM_SCREEN__
#define __SIM_SCREEN__

#include "../JuceLibraryCode/JuceHeader.h"
#include <inttypes.h>

class SimScreen  : public Component
{
public:
    SimScreen();
    ~SimScreen();

    void paint (Graphics& g);
    void resized();
    void mouseDrag (const MouseEvent& e);
    void mouseUp (const MouseEvent& e);
    void mouseDown (const MouseEvent& e);
    void mouseExit (const MouseEvent& e);

    void position(const Point<float> p);
    void position(uint16_t x, uint16_t y);
    void release();

    juce_UseDebuggingNewOperator


private:
    SimScreen (const SimScreen&);
    const SimScreen& operator= (const SimScreen&);

/*     BlipBox* blipbox; */
};


#endif   // __SIM_SCREEN__
