/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  22 Aug 2011 4:36:34pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_APPLICATIONSETTINGSCOMPONENT_APPLICATIONSETTINGSCOMPONENT_12275364__
#define __JUCER_HEADER_APPLICATIONSETTINGSCOMPONENT_APPLICATIONSETTINGSCOMPONENT_12275364__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ApplicationSettingsComponent  : public Component,
                                      public ButtonListener,
                                      public ComboBoxListener
{
public:
    //==============================================================================
    ApplicationSettingsComponent ();
    ~ApplicationSettingsComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void saveSettingsToFile();
    void loadSettingsFromFile();
    int showModalDialog(Component* ref);

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
    Label* label;
    TextButton* connectButton;
    Label* label2;
    ComboBox* serialSpeedComboBox;
    TextButton* okButton;
    TextEditor* presetDirectoryEditor;
    Label* label3;
    TextButton* cancelButton;
    Label* label4;
    ComboBox* midiOutputComboBox;
    ComboBox* serialPortComboBox;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ApplicationSettingsComponent (const ApplicationSettingsComponent&);
    const ApplicationSettingsComponent& operator= (const ApplicationSettingsComponent&);
};


#endif   // __JUCER_HEADER_APPLICATIONSETTINGSCOMPONENT_APPLICATIONSETTINGSCOMPONENT_12275364__
