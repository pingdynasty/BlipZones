/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  9 Dec 2011 1:40:09pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MIDIPITCHBENDCOMPONENT_MIDIPITCHBENDCOMPONENT_33ADDFC__
#define __JUCER_HEADER_MIDIPITCHBENDCOMPONENT_MIDIPITCHBENDCOMPONENT_33ADDFC__

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
class MidiPitchBendComponent  : public ActionComponent,
                                public SliderListener
{
public:
    //==============================================================================
    MidiPitchBendComponent ();
    ~MidiPitchBendComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    Action* getAction(){
      return action;
    }
    void loadAction(Action* anaction);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MidiPitchBendAction* action;
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
    MidiPitchBendComponent (const MidiPitchBendComponent&);
    const MidiPitchBendComponent& operator= (const MidiPitchBendComponent&);
};


#endif   // __JUCER_HEADER_MIDIPITCHBENDCOMPONENT_MIDIPITCHBENDCOMPONENT_33ADDFC__
