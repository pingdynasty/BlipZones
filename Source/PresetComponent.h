/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  23 Jan 2012 2:56:11pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_4E1B48DD__
#define __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_4E1B48DD__

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
                         public ButtonListener,
                         public ComboBoxListener
{
public:
    //==============================================================================
    PresetComponent (Preset* p);
    ~PresetComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void initialise();
    void release();
    Preset* getPreset();
    void requestPreset();
    void sendPreset();
    void loadPreset(uint8_t index);
    void loadPreset(Preset* preset);
    void savePreset(uint8_t index);
/*     void selectZone(uint8_t index); */
    void addZone();
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
    //[/UserVariables]

    //==============================================================================
    TextButton* sendButton;
    Label* label7;
    ComboBox* presetComboBox;
    TextButton* requestButton;
    TextButton* saveButton;
    TextButton* loadButton;
    TextButton* settingsButton;
    ToggleButton* runButton;
    ComboBox* zoneTypeComboBox;
    TextButton* addButton;
    ZoneListBox* zones;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    PresetComponent (const PresetComponent&);
    const PresetComponent& operator= (const PresetComponent&);
};


#endif   // __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_4E1B48DD__
