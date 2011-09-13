/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  22 Aug 2011 12:57:00pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_376ED187__
#define __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_376ED187__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiZonePreset.h"
//[/Headers]

#include "MidiZoneComponent.h"


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
    MidiZonePreset* getPreset();
    void requestPreset();
    void sendPreset();
    void loadPreset(uint8_t index);
    void loadZones();
    void selectZone(uint8_t index);
    void loadFile();
    void saveFile();
    void openSettings();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MidiZonePreset *preset;
    MidiZoneComponent* zonecomponents[MIDI_ZONES_IN_PRESET];
    //[/UserVariables]

    //==============================================================================
    TextButton* sendButton;
    Label* label;
    Label* dataLabel;
    Label* label3;
    Label* label4;
    Label* label5;
    Label* label6;
    Label* label7;
    ComboBox* presetComboBox;
    TextButton* requestButton;
    MidiZoneComponent* zone1;
    Label* label8;
    MidiZoneComponent* zone2;
    MidiZoneComponent* zone3;
    MidiZoneComponent* zone4;
    MidiZoneComponent* zone5;
    MidiZoneComponent* zone6;
    MidiZoneComponent* zone7;
    MidiZoneComponent* zone8;
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


#endif   // __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_376ED187__
