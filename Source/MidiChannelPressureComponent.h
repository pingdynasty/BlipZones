/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  8 Feb 2012 11:15:39am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MIDICHANNELPRESSURECOMPONENT_MIDICHANNELPRESSURECOMPONENT_23EA44F3__
#define __JUCER_HEADER_MIDICHANNELPRESSURECOMPONENT_MIDICHANNELPRESSURECOMPONENT_23EA44F3__

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
class MidiChannelPressureComponent  : public ActionComponent,
                                      public SliderListener
{
public:
    //==============================================================================
    MidiChannelPressureComponent ();
    ~MidiChannelPressureComponent();

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
    MidiChannelPressureAction* action;
    //[/UserVariables]

    //==============================================================================
    Slider* channelSlider;
    Slider* maxSlider;
    Slider* minSlider;
    Label* label;
    Label* label2;
    Label* label3;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MidiChannelPressureComponent (const MidiChannelPressureComponent&);
    const MidiChannelPressureComponent& operator= (const MidiChannelPressureComponent&);
};


#endif   // __JUCER_HEADER_MIDICHANNELPRESSURECOMPONENT_MIDICHANNELPRESSURECOMPONENT_23EA44F3__
