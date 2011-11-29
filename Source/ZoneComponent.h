/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  28 Nov 2011 10:45:05pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_ZONECOMPONENT_ZONECOMPONENT_36701ABB__
#define __JUCER_HEADER_ZONECOMPONENT_ZONECOMPONENT_36701ABB__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Zone.h"
//[/Headers]

#include "ActionComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ZoneComponent  : public Component,
                       public ComboBoxListener,
                       public SliderListener
{
public:
    //==============================================================================
    ZoneComponent ();
    ~ZoneComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    Zone* getZone(){
      return zone;
    }
    void loadZone(Zone* zone);
    void loadAction(Action* action);
    void handlePositionMessage(uint16_t x, uint16_t y);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void sliderValueChanged (Slider* sliderThatWasMoved);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Zone* zone;
    //[/UserVariables]

    //==============================================================================
    ActionComponent* component;
    ComboBox* typeComboBox;
    Slider* Xslider;
    Slider* Yslider;
    ComboBox* typeComboBox2;
    ComboBox* typeComboBox3;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ZoneComponent (const ZoneComponent&);
    const ZoneComponent& operator= (const ZoneComponent&);
};


#endif   // __JUCER_HEADER_ZONECOMPONENT_ZONECOMPONENT_36701ABB__
