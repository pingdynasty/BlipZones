/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  1 Sep 2011 4:54:09pm

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
#include "ApplicationConfiguration.h"
#include "Zone.h"
//[/Headers]

#include "MidiZoneComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

const bool sendUpdateMessage = false;
const bool sendMessageSynchronously = true;
const bool allowNudgingOfOtherValues = true;

void MidiZoneComponent::handlePositionMessage(uint16_t x, uint16_t y){
  x = x*10/1023;
  y = y*8/1023;
  const MessageManagerLock mmLock;
  if(abs(getZone()->from.getColumn() - x) < abs(getZone()->to.getColumn() - x))
    Xslider->setMinValue(x, sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  else
    Xslider->setMaxValue(x, sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  if(abs(getZone()->from.getRow() - y) < abs(getZone()->to.getRow() - y))
    Yslider->setMinValue(y, sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  else
    Yslider->setMaxValue(y, sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
}

void MidiZoneComponent::updateZoneArea(){
  zone->from.setRow(Yslider->getMinValue());
  zone->to.setRow(Yslider->getMaxValue());
  zone->from.setColumn(Xslider->getMinValue());
  zone->to.setColumn(Xslider->getMaxValue());
}

void MidiZoneComponent::loadZone(Zone* azone){
  zone = azone;
  Xslider->setMinValue(zone->from.getColumn(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Yslider->setMinValue(zone->from.getRow(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Xslider->setMaxValue(zone->to.getColumn(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Yslider->setMaxValue(zone->to.getRow(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
}

//[/MiscUserDefs]

//==============================================================================
MidiZoneComponent::MidiZoneComponent ()
    : Component (L"MidiZone"),
      typeComboBox1 (0),
      typeComboBox2 (0),
      channelSlider (0),
      maxSlider (0),
      minSlider (0),
      Xslider (0),
      Yslider (0),
      dataSlider (0),
      typeComboBox3 (0)
{
    addAndMakeVisible (typeComboBox1 = new ComboBox (L"Type"));
    typeComboBox1->setEditableText (false);
    typeComboBox1->setJustificationType (Justification::centredLeft);
    typeComboBox1->setTextWhenNothingSelected (String::empty);
    typeComboBox1->setTextWhenNoChoicesAvailable (L"(no choices)");
    typeComboBox1->addItem (L"Control Change", 1);
    typeComboBox1->addItem (L"Note On", 2);
    typeComboBox1->addItem (L"Pitch Bend", 3);
    typeComboBox1->addItem (L"NRPN", 4);
    typeComboBox1->addItem (L"Channel Pressure", 5);
    typeComboBox1->addItem (L"Polyphonic Aftertouch", 6);
    typeComboBox1->addItem (L"Select Preset", 7);
    typeComboBox1->addListener (this);

    addAndMakeVisible (typeComboBox2 = new ComboBox (L"Type"));
    typeComboBox2->setEditableText (false);
    typeComboBox2->setJustificationType (Justification::centredLeft);
    typeComboBox2->setTextWhenNothingSelected (String::empty);
    typeComboBox2->setTextWhenNoChoicesAvailable (L"(no choices)");
    typeComboBox2->addItem (L"Horizontal Slider", 1);
    typeComboBox2->addItem (L"Vertical Slider", 2);
    typeComboBox2->addItem (L"Momentary Button", 3);
    typeComboBox2->addItem (L"Toggle Button", 4);
    typeComboBox2->addListener (this);

    addAndMakeVisible (channelSlider = new Slider (L"channel"));
    channelSlider->setRange (1, 16, 1);
    channelSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    channelSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    channelSlider->addListener (this);

    addAndMakeVisible (maxSlider = new Slider (L"max"));
    maxSlider->setRange (0, 127, 1);
    maxSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    maxSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    maxSlider->addListener (this);

    addAndMakeVisible (minSlider = new Slider (L"min"));
    minSlider->setRange (0, 127, 1);
    minSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    minSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    minSlider->addListener (this);

    addAndMakeVisible (Xslider = new Slider (L"X"));
    Xslider->setRange (0, 10, 1);
    Xslider->setSliderStyle (Slider::TwoValueHorizontal);
    Xslider->setTextBoxStyle (Slider::NoTextBox, false, 40, 20);
    Xslider->addListener (this);

    addAndMakeVisible (Yslider = new Slider (L"Y"));
    Yslider->setRange (0, 8, 1);
    Yslider->setSliderStyle (Slider::TwoValueVertical);
    Yslider->setTextBoxStyle (Slider::NoTextBox, false, 40, 20);
    Yslider->addListener (this);

    addAndMakeVisible (dataSlider = new Slider (L"data"));
    dataSlider->setRange (0, 127, 1);
    dataSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    dataSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    dataSlider->addListener (this);

    addAndMakeVisible (typeComboBox3 = new ComboBox (L"Type"));
    typeComboBox3->setEditableText (false);
    typeComboBox3->setJustificationType (Justification::centredLeft);
    typeComboBox3->setTextWhenNothingSelected (String::empty);
    typeComboBox3->setTextWhenNoChoicesAvailable (L"(no choices)");
    typeComboBox3->addItem (L"Bar", 1);
    typeComboBox3->addItem (L"Fill", 2);
    typeComboBox3->addItem (L"Dot", 3);
    typeComboBox3->addItem (L"None", 4);
    typeComboBox3->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 100);


    //[Constructor] You can add your own custom stuff here..
//     toggleButton->setRadioGroupId(TOGGLE_BUTTON_RADIO_GROUP);

    //[/Constructor]
}

MidiZoneComponent::~MidiZoneComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (typeComboBox1);
    deleteAndZero (typeComboBox2);
    deleteAndZero (channelSlider);
    deleteAndZero (maxSlider);
    deleteAndZero (minSlider);
    deleteAndZero (Xslider);
    deleteAndZero (Yslider);
    deleteAndZero (dataSlider);
    deleteAndZero (typeComboBox3);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiZoneComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xf5f9ea0));
    g.fillRoundedRectangle (1.0f, 4.0f, 510.0f, 67.0f, 3.5000f);

    g.setColour (Colours::cadetblue);
    g.drawRoundedRectangle (1.0f, 4.0f, 510.0f, 67.0f, 3.5000f, 0.5000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiZoneComponent::resized()
{
    typeComboBox1->setBounds (104, 8, 136, 24);
    typeComboBox2->setBounds (104, 40, 136, 24);
    channelSlider->setBounds (248, 8, 32, 56);
    maxSlider->setBounds (368, 8, 32, 56);
    minSlider->setBounds (328, 8, 32, 56);
    Xslider->setBounds (408, 8, 56, 56);
    Yslider->setBounds (472, 8, 32, 56);
    dataSlider->setBounds (288, 8, 32, 56);
    typeComboBox3->setBounds (8, 40, 88, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidiZoneComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == typeComboBox1)
    {
        //[UserComboBoxCode_typeComboBox1] -- add your combo box handling code here..
      updateZoneType();
        //[/UserComboBoxCode_typeComboBox1]
    }
    else if (comboBoxThatHasChanged == typeComboBox2)
    {
        //[UserComboBoxCode_typeComboBox2] -- add your combo box handling code here..
      updateZoneType();
      // TODO figure out how to set default values only when combo is manually changed
//       if(getZone()->_type & BUTTON_SLIDER_ZONE_BIT)
// 	typeComboBox3->setSelectedId(2, false); // FILL
//       else
// 	typeComboBox3->setSelectedId(1, false); // BAR
        //[/UserComboBoxCode_typeComboBox2]
    }
    else if (comboBoxThatHasChanged == typeComboBox3)
    {
        //[UserComboBoxCode_typeComboBox3] -- add your combo box handling code here..
      updateZoneType();
        //[/UserComboBoxCode_typeComboBox3]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void MidiZoneComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == channelSlider)
    {
        //[UserSliderCode_channelSlider] -- add your slider handling code here..
      updateZoneChannel();
        //[/UserSliderCode_channelSlider]
    }
    else if (sliderThatWasMoved == maxSlider)
    {
        //[UserSliderCode_maxSlider] -- add your slider handling code here..
      updateZoneRange();
        //[/UserSliderCode_maxSlider]
    }
    else if (sliderThatWasMoved == minSlider)
    {
        //[UserSliderCode_minSlider] -- add your slider handling code here..
      updateZoneRange();
        //[/UserSliderCode_minSlider]
    }
    else if (sliderThatWasMoved == Xslider)
    {
        //[UserSliderCode_Xslider] -- add your slider handling code here..
      updateZoneArea();
        //[/UserSliderCode_Xslider]
    }
    else if (sliderThatWasMoved == Yslider)
    {
        //[UserSliderCode_Yslider] -- add your slider handling code here..
      updateZoneArea();
        //[/UserSliderCode_Yslider]
    }
    else if (sliderThatWasMoved == dataSlider)
    {
        //[UserSliderCode_dataSlider] -- add your slider handling code here..
      updateZoneData();
        //[/UserSliderCode_dataSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiZoneComponent" componentName="MidiZone"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="100">
  <BACKGROUND backgroundColour="ffffffff">
    <ROUNDRECT pos="1 4 510 67" cornerSize="3.5" fill="solid: f5f9ea0" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff5f9ea0"/>
  </BACKGROUND>
  <COMBOBOX name="Type" id="c1f4660eabe8fccb" memberName="typeComboBox1"
            virtualName="" explicitFocusOrder="0" pos="104 8 136 24" editable="0"
            layout="33" items="Control Change&#10;Note On&#10;Pitch Bend&#10;NRPN&#10;Channel Pressure&#10;Polyphonic Aftertouch&#10;Select Preset"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Type" id="c60683b64f639182" memberName="typeComboBox2"
            virtualName="" explicitFocusOrder="0" pos="104 40 136 24" editable="0"
            layout="33" items="Horizontal Slider&#10;Vertical Slider&#10;Momentary Button&#10;Toggle Button"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="channel" id="3b517834e41dae35" memberName="channelSlider"
          virtualName="" explicitFocusOrder="0" pos="248 8 32 56" min="1"
          max="16" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="max" id="aa57fa59b0b89fff" memberName="maxSlider" virtualName=""
          explicitFocusOrder="0" pos="368 8 32 56" min="0" max="127" int="1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="min" id="b0ac6409986e9469" memberName="minSlider" virtualName=""
          explicitFocusOrder="0" pos="328 8 32 56" min="0" max="127" int="1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="X" id="9789276617163945" memberName="Xslider" virtualName=""
          explicitFocusOrder="0" pos="408 8 56 56" min="0" max="10" int="1"
          style="TwoValueHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Y" id="159851448f456c82" memberName="Yslider" virtualName=""
          explicitFocusOrder="0" pos="472 8 32 56" min="0" max="8" int="1"
          style="TwoValueVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="data" id="e3a29d8ffb183a23" memberName="dataSlider" virtualName=""
          explicitFocusOrder="0" pos="288 8 32 56" min="0" max="127" int="1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Type" id="ee97d6a8e0e218c6" memberName="typeComboBox3"
            virtualName="" explicitFocusOrder="0" pos="8 40 88 24" editable="0"
            layout="33" items="Bar&#10;Fill&#10;Dot&#10;None" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
