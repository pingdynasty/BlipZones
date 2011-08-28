/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  13 Aug 2011 8:50:28am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_BLIPSIMCOMPONENT_BLIPSIMCOMPONENT_7D6AD0FA__
#define __JUCER_HEADER_BLIPSIMCOMPONENT_BLIPSIMCOMPONENT_7D6AD0FA__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "SimScreen.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class BlipSimComponent  : public Component
{
public:
    //==============================================================================
    BlipSimComponent ();
    ~BlipSimComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void mouseDrag (const MouseEvent& e);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    SimScreen* screen;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    BlipSimComponent (const BlipSimComponent&);
    const BlipSimComponent& operator= (const BlipSimComponent&);
};


#endif   // __JUCER_HEADER_BLIPSIMCOMPONENT_BLIPSIMCOMPONENT_7D6AD0FA__
