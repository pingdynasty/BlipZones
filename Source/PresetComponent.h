/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  3 Feb 2012 10:27:47am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_2713182__
#define __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_2713182__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Preset.h"
//[/Headers]

#include "ZoneListBox.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PresetComponent  : public Component,
                         public ComboBoxListener,
                         public ButtonListener
{
public:
    //==============================================================================
    PresetComponent (Preset* p);
    ~PresetComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    Preset* getPreset();
    void addZone();
    void loadZones();
/*     void selectZone(uint8_t index); */
/*     uint8_t getSelectedZoneIndex(); */
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Preset* preset;
    //[/UserVariables]

    //==============================================================================
    ComboBox* zoneTypeComboBox;
    TextButton* addButton;
    ZoneListBox* zones;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    PresetComponent (const PresetComponent&);
    const PresetComponent& operator= (const PresetComponent&);
};


#endif   // __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_2713182__
