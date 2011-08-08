/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  8 Aug 2011 2:32:59am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MIDIZONECOMPONENT_MIDIZONECOMPONENT_9B69AC03__
#define __JUCER_HEADER_MIDIZONECOMPONENT_MIDIZONECOMPONENT_9B69AC03__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiZone.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.
                                                                    //[/Comments]
*/
class MidiZoneComponent  : public Component,
                           public ComboBoxListener,
                           public SliderListener
{
public:
    //==============================================================================
    MidiZoneComponent ();
    ~MidiZoneComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    MidiZone* getZone(){
      return midizone;
    }
    void setZone(MidiZone* _zone){
      midizone = _zone;
    }
    void loadZone(MidiZone* zone);
    void updateZoneType();
    void setZoneType(MidiZone* zone);
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
    MidiZone* midizone;
    //[/UserVariables]

    //==============================================================================
    ComboBox* typeComboBox1;
    ComboBox* typeComboBox2;
    Slider* channelSlider;
    Slider* maxSlider;
    Slider* minSlider;
    Slider* Xslider;
    Slider* Yslider;
    Slider* dataSlider;
    ComboBox* typeComboBox3;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MidiZoneComponent (const MidiZoneComponent&);
    const MidiZoneComponent& operator= (const MidiZoneComponent&);
};


#endif   // __JUCER_HEADER_MIDIZONECOMPONENT_MIDIZONECOMPONENT_9B69AC03__
