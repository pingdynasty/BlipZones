/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  8 Feb 2012 12:20:54pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MIDIAFTERTOUCHCOMPONENT_MIDIAFTERTOUCHCOMPONENT_1E72B421__
#define __JUCER_HEADER_MIDIAFTERTOUCHCOMPONENT_MIDIAFTERTOUCHCOMPONENT_1E72B421__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "ActionComponent.h"
#include "Action.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidiAftertouchComponent  : public ActionComponent,
                                 public SliderListener
{
public:
    //==============================================================================
    MidiAftertouchComponent ();
    ~MidiAftertouchComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    Action* getAction(){
      return action;
    }
    void loadAction(Action* action);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MidiAftertouchAction* action;
    //[/UserVariables]

    //==============================================================================
    Slider* channelSlider;
    Slider* maxSlider;
    Slider* minSlider;
    Slider* dataSlider;
    Label* label;
    Label* label2;
    Label* label3;
    Label* label4;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MidiAftertouchComponent (const MidiAftertouchComponent&);
    const MidiAftertouchComponent& operator= (const MidiAftertouchComponent&);
};


#endif   // __JUCER_HEADER_MIDIAFTERTOUCHCOMPONENT_MIDIAFTERTOUCHCOMPONENT_1E72B421__
