/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  2 Feb 2012 12:05:26pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_CONFIGURATIONCOMPONENT_CONFIGURATIONCOMPONENT_72C6D96A__
#define __JUCER_HEADER_CONFIGURATIONCOMPONENT_CONFIGURATIONCOMPONENT_72C6D96A__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Preset.h"
//[/Headers]

#include "PresetComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ConfigurationComponent  : public Component,
                                public ButtonListener,
                                public ComboBoxListener
{
public:
    //==============================================================================
    ConfigurationComponent ();
    ~ConfigurationComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void requestPreset();
    void sendPreset();
    void loadPreset(uint8_t index);
    void loadPreset(Preset* preset);
/*     void savePreset(uint8_t index); */
    void loadFile();
    void saveFile();
    void openSettings();
    Preset* getCurrentPreset();
    Preset* getDefaultPreset();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    TextButton* sendButton;
    TextButton* requestButton;
    TextButton* saveButton;
    TextButton* loadButton;
    TextButton* settingsButton;
    ToggleButton* runButton;
    PresetComponent* component;
    Label* label7;
    ComboBox* presetComboBox;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ConfigurationComponent (const ConfigurationComponent&);
    const ConfigurationComponent& operator= (const ConfigurationComponent&);
};


#endif   // __JUCER_HEADER_CONFIGURATIONCOMPONENT_CONFIGURATIONCOMPONENT_72C6D96A__
