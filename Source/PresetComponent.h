/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  28 Nov 2011 10:45:07pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_C7904E5D__
#define __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_C7904E5D__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Preset.h"
//[/Headers]

#include "ZoneComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PresetComponent  : public Component,
                         public ButtonListener,
                         public ComboBoxListener
{
public:
    //==============================================================================
    PresetComponent ();
    ~PresetComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void initialise();
    void handleReleaseMessage();
    void handlePositionMessage(uint16_t x, uint16_t y);
    void handleParameterMessage(uint8_t pid, uint16_t value);
    void release();
    Preset* getPreset();
    void requestPreset();
    void sendPreset();
    void loadPreset(uint8_t index);
    void savePreset(uint8_t index);
    void loadZones();
    void selectZone(uint8_t index);
    void loadFile();
    void saveFile();
    void openSettings();
    uint8_t getSelectedZoneIndex();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Preset* preset;
/*     ScopedPointer<Preset> preset; */
    Array<ZoneComponent*> components;
    //[/UserVariables]

    //==============================================================================
    ZoneComponent* zone8;
    ZoneComponent* zone7;
    ZoneComponent* zone6;
    ZoneComponent* zone5;
    ZoneComponent* zone4;
    ZoneComponent* zone3;
    ZoneComponent* zone2;
    TextButton* sendButton;
    Label* label7;
    ComboBox* presetComboBox;
    TextButton* requestButton;
    ZoneComponent* zone1;
    ToggleButton* toggleButton1;
    ToggleButton* toggleButton2;
    ToggleButton* toggleButton3;
    ToggleButton* toggleButton4;
    ToggleButton* toggleButton5;
    ToggleButton* toggleButton6;
    ToggleButton* toggleButton7;
    ToggleButton* toggleButton8;
    TextButton* saveButton;
    TextButton* loadButton;
    TextButton* settingsButton;
    ToggleButton* runButton;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    PresetComponent (const PresetComponent&);
    const PresetComponent& operator= (const PresetComponent&);
};


#endif   // __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_C7904E5D__
