/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  10 Jan 2012 12:08:08am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "SelectPresetComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SelectPresetComponent::SelectPresetComponent ()
    : presetSlider (0),
      label (0)
{
    addAndMakeVisible (presetSlider = new Slider (L"preset"));
    presetSlider->setRange (1, 8, 1);
    presetSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    presetSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    presetSlider->addListener (this);

    addAndMakeVisible (label = new Label (L"new label",
                                          L"preset"));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 100);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SelectPresetComponent::~SelectPresetComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (presetSlider);
    deleteAndZero (label);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SelectPresetComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xf5f9ea0));
    g.fillRoundedRectangle (0.0f, 0.0f, 510.0f, 68.0f, 3.5000f);

    g.setColour (Colours::cadetblue);
    g.drawRoundedRectangle (0.0f, 0.0f, 510.0f, 68.0f, 3.5000f, 0.5000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SelectPresetComponent::resized()
{
    presetSlider->setBounds (448, 8, 56, 24);
    label->setBounds (392, 8, 55, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SelectPresetComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == presetSlider)
    {
        //[UserSliderCode_presetSlider] -- add your slider handling code here..
      action->setPresetIndex((uint8_t)presetSlider->getValue() - 1);
        //[/UserSliderCode_presetSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SelectPresetComponent::loadAction(Action* anaction){
  action = dynamic_cast<SelectPresetAction*>(anaction);
  if(action != NULL){
    presetSlider->setValue(action->getPresetIndex()+1, sendUpdateMessage, sendMessageSynchronously);
  }else{
    std::cout << "null action, dynamic cast failed " << anaction << std::endl;
  }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SelectPresetComponent" componentName=""
                 parentClasses="public ActionComponent" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="100">
  <BACKGROUND backgroundColour="ffffffff">
    <ROUNDRECT pos="0 0 510 68" cornerSize="3.5" fill="solid: f5f9ea0" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff5f9ea0"/>
  </BACKGROUND>
  <SLIDER name="preset" id="b0ac6409986e9469" memberName="presetSlider"
          virtualName="" explicitFocusOrder="0" pos="448 8 56 24" min="1"
          max="8" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="6bf549a531a0e0e9" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="392 8 55 24" edTextCol="ff000000"
         edBkgCol="0" labelText="preset" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
