/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  2 Feb 2012 4:29:51pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_ZONECOMPONENT_ZONECOMPONENT_288257A1__
#define __JUCER_HEADER_ZONECOMPONENT_ZONECOMPONENT_288257A1__

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
                       public SliderListener,
                       public ButtonListener
{
public:
    //==============================================================================
    ZoneComponent (Zone* z);
    ~ZoneComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    Zone* getZone(){
      return zone;
    }
    void loadZone(Zone* zone);
private:
    void loadAction(Action* action);
    void setZoneType(ZoneType type);
public:
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* deleteButtonSmall_png;
    static const int deleteButtonSmall_pngSize;


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Zone* zone;
    //[/UserVariables]

    //==============================================================================
    ActionComponent* component;
    ComboBox* actionTypeComboBox;
    Slider* Xslider;
    Slider* Yslider;
    ComboBox* displayTypeComboBox;
    Label* typeLabel;
    ImageButton* deleteButton;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ZoneComponent (const ZoneComponent&);
    const ZoneComponent& operator= (const ZoneComponent&);
};


#endif   // __JUCER_HEADER_ZONECOMPONENT_ZONECOMPONENT_288257A1__
