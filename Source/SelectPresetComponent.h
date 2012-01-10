/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  10 Jan 2012 12:08:08am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SELECTPRESETCOMPONENT_SELECTPRESETCOMPONENT_DB01CCCD__
#define __JUCER_HEADER_SELECTPRESETCOMPONENT_SELECTPRESETCOMPONENT_DB01CCCD__

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
class SelectPresetComponent  : public ActionComponent,
                               public SliderListener
{
public:
    //==============================================================================
    SelectPresetComponent ();
    ~SelectPresetComponent();

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
    SelectPresetAction* action;
    //[/UserVariables]

    //==============================================================================
    Slider* presetSlider;
    Label* label;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    SelectPresetComponent (const SelectPresetComponent&);
    const SelectPresetComponent& operator= (const SelectPresetComponent&);
};


#endif   // __JUCER_HEADER_SELECTPRESETCOMPONENT_SELECTPRESETCOMPONENT_DB01CCCD__
