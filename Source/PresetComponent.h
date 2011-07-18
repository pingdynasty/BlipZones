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
#include "juce.h"
#include "BlipBox.h"
#include "MidiZone.h"
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
    void init(){
      for(int i=0; i<MIDI_ZONE_PRESETS; ++i)
	presets[i].preset = i;
      blipbox = new BlipBox();
      blipbox->connect();
      presetComboBox->setSelectedItemIndex(0, false);
      loadPreset(presetComboBox->getSelectedItemIndex());
    }
    void release(){
      if(blipbox != NULL)
	blipbox->disconnect();
      delete blipbox;
    }
    MidiZone& getZone(){
      return preset->getZone(zoneComboBox->getSelectedItemIndex());
    }
    void loadPreset(uint8_t index){
      if(index < MIDI_ZONE_PRESETS)
	preset = &presets[index];
      zoneComboBox->setSelectedItemIndex(0, false);
      loadZone(zoneComboBox->getSelectedItemIndex());
    }
    void loadZone(uint8_t index){
      MidiZone& zone = preset->getZone(index);
      typeComboBox->setSelectedItemIndex(zone.getTypeIndex(), false);
      channelSlider->setValue(zone.getChannel(), false);
      data1Slider->setValue(zone._data1, false);
      Xslider->setMinValue(zone._from_x, false);
      Yslider->setMinValue(zone._from_y, false);
      Xslider->setMaxValue(zone._to_x, false);
      Yslider->setMaxValue(zone._to_y, false);
      blipbox->drawMidiZone(getZone());
    }
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
    BlipBox* blipbox;
    MidiZonePreset* preset;
    MidiZonePreset presets[MIDI_ZONE_PRESETS];
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
