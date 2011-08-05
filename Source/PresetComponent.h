/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  11 Jul 2011 5:46:50pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_D44A8DE6__
#define __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_D44A8DE6__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "globals.h"
class BlipClient;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PresetComponent  : public Component,
                         public ComboBoxListener,
                         public SliderListener,
                         public ButtonListener
{
public:
    //==============================================================================
    PresetComponent ();
    ~PresetComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void init();
    void handleReleaseMessage();
    void handlePositionMessage(uint16_t x, uint16_t y);
    void handleParameterMessage(uint8_t pid, uint16_t value);
    void release();
    MidiZone& getZone();
    void loadPreset(uint8_t index);
    void loadZone(uint8_t index);
    void loadZone(MidiZone& zone);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    BlipClient* client;
    //[/UserVariables]

    //==============================================================================
    ComboBox* zoneComboBox;
    ComboBox* typeComboBox;
    Slider* Xslider;
    Slider* Yslider;
    Slider* channelSlider;
    Slider* data1Slider;
    TextButton* sendButton;
    Label* label;
    Label* label2;
    Label* label3;
    Label* label4;
    Label* label5;
    Label* label6;
    Label* label7;
    ComboBox* presetComboBox;
    TextButton* showButton;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    PresetComponent (const PresetComponent&);
    const PresetComponent& operator= (const PresetComponent&);
};


#endif   // __JUCER_HEADER_PRESETCOMPONENT_PRESETCOMPONENT_D44A8DE6__
