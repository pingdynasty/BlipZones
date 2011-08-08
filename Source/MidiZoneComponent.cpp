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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MidiZoneComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

void MidiZoneComponent::handlePositionMessage(uint16_t x, uint16_t y){
  x = x*10/1023;
  y = y*8/1023;
  const MessageManagerLock mmLock;
  if(abs(getZone()->_from_column - x) < abs(getZone()->_to_column - x))
    Xslider->setMinValue(x, true);
  else
    Xslider->setMaxValue(x, true);
  if(abs(getZone()->_from_row - y) < abs(getZone()->_to_row - y))
    Yslider->setMinValue(y, true);
  else
    Yslider->setMaxValue(y, true);
}

void MidiZoneComponent::updateZoneType(){
  uint8_t type = 0;
  uint8_t status = 0;
  type = MIDI_ZONE_TYPE;

  switch(typeComboBox1->getSelectedId()){
  case 1: // Control Change
    status = MIDI_CONTROL_CHANGE;
    break;
  case 2: // Note On
    status = MIDI_NOTE_ON;
    break;
  case 3: // Pitch Bend
    status = MIDI_PITCH_BEND;
    break;
  case 4: // NRPN
    status = MIDI_CONTROL_CHANGE;
    type = NRPN_ZONE_TYPE;
    break;
  case 5: // Channel Pressure
    status = MIDI_CHANNEL_PRESSURE;
    break;
  case 6: // Polyphonic Aftertouch
    status = MIDI_AFTERTOUCH;
    break;
  }

  switch(typeComboBox2->getSelectedId()){
  case 1: // Horizontal Slider
    type |= HORIZONTAL_VERTICAL_ZONE_BIT;
    break;
  case 2: // Vertical Slider
    break;
  case 3: // Momentary Button
    type |= MOMENTARY_TOGGLE_ZONE_BIT | BUTTON_SLIDER_ZONE_BIT;
    break;
  case 4: // Toggle Button
    type |= BUTTON_SLIDER_ZONE_BIT;
    break;
  }

  switch(typeComboBox3->getSelectedId()){
  case 1:
    type |= BAR_DISPLAY_TYPE;
    break;
  case 2:
    type |= FILL_DISPLAY_TYPE;
    break;
  case 3:
    type |= DOT_DISPLAY_TYPE;
    break;
  case 4:
    type |= NO_DISPLAY_TYPE;
    break;
  }

  status |= (uint8_t)channelSlider->getValue()-1;
  getZone()->_status = status;
  getZone()->_type = type;
}

void MidiZoneComponent::setZoneType(MidiZone* zone){
  switch(zone->_type & ZONE_TYPE_MASK){
  case MIDI_ZONE_TYPE:
    switch(zone->_status & 0xf0){
    case MIDI_CONTROL_CHANGE:
      typeComboBox1->setSelectedId(1, false); // Control Change
      break;
    case MIDI_NOTE_ON:
      typeComboBox1->setSelectedId(2, false); // Note On
      break;
    case MIDI_PITCH_BEND:
      typeComboBox1->setSelectedId(3, false); // Pitch Bend
      break;
    case MIDI_CHANNEL_PRESSURE:
      typeComboBox1->setSelectedId(5, false); // Channel Pressure
      break;
    case MIDI_AFTERTOUCH:
      typeComboBox1->setSelectedId(6, false); // Polyphonic Aftertouch
      break;
    }
    break;
  case NRPN_ZONE_TYPE:
    typeComboBox1->setSelectedId(4, false); // NRPN
    break;
  case SELECTOR_ZONE_TYPE:
  case EMPTY_ZONE_TYPE:
    typeComboBox1->setSelectedId(0, false);
    break;
  }

  if(zone->_type & BUTTON_SLIDER_ZONE_BIT){
    if(zone->_type & MOMENTARY_TOGGLE_ZONE_BIT)
      typeComboBox2->setSelectedId(3, false); // Momentary Button
    else
      typeComboBox2->setSelectedId(4, false); // Toggle Button
  }else{
    if(zone->_type & HORIZONTAL_VERTICAL_ZONE_BIT)
      typeComboBox2->setSelectedId(1, false); // Horizontal Slider
    else
      typeComboBox2->setSelectedId(2, false); // Vertical Slider
  }

  switch(zone->_type & DISPLAY_TYPE_MASK){
  case BAR_DISPLAY_TYPE:
    typeComboBox3->setSelectedId(1, false);
    break;
  case FILL_DISPLAY_TYPE:
    typeComboBox3->setSelectedId(2, false);
    break;
  case DOT_DISPLAY_TYPE:
    typeComboBox3->setSelectedId(3, false);
    break;
  case NO_DISPLAY_TYPE:
    typeComboBox3->setSelectedId(4, false);
    break;
  }

  channelSlider->setValue((zone->_status & 0x0f)+1);
}

void MidiZoneComponent::loadZone(MidiZone* zone){
  setZoneType(zone);
  dataSlider->setValue(zone->_data1, false);
  maxSlider->setValue(zone->_max, false);
  minSlider->setValue(zone->_min, false);
  Xslider->setMinValue(zone->_from_column, false);
  Yslider->setMinValue(zone->_from_row, false);
  Xslider->setMaxValue(zone->_to_column, false);
  Yslider->setMaxValue(zone->_to_row, false);
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
    channelSlider->setSliderStyle (Slider::Rotary);
    channelSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    channelSlider->addListener (this);

    addAndMakeVisible (maxSlider = new Slider (L"max"));
    maxSlider->setRange (0, 127, 1);
    maxSlider->setSliderStyle (Slider::Rotary);
    maxSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    maxSlider->addListener (this);

    addAndMakeVisible (minSlider = new Slider (L"min"));
    minSlider->setRange (0, 127, 1);
    minSlider->setSliderStyle (Slider::Rotary);
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
    dataSlider->setSliderStyle (Slider::Rotary);
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

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiZoneComponent::resized()
{
    typeComboBox1->setBounds (96, 0, 88, 24);
    typeComboBox2->setBounds (96, 32, 88, 24);
    channelSlider->setBounds (192, 0, 32, 56);
    maxSlider->setBounds (312, 0, 32, 56);
    minSlider->setBounds (272, 0, 32, 56);
    Xslider->setBounds (352, 0, 56, 56);
    Yslider->setBounds (416, 0, 32, 56);
    dataSlider->setBounds (232, 0, 32, 56);
    typeComboBox3->setBounds (0, 32, 88, 24);
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
        //[/UserComboBoxCode_typeComboBox1]
    }
    else if (comboBoxThatHasChanged == typeComboBox2)
    {
        //[UserComboBoxCode_typeComboBox2] -- add your combo box handling code here..
      updateZoneType();
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
      midizone->_status = (midizone->_status & 0xf0) | ((uint8_t)sliderThatWasMoved->getValue() + 1);
        //[/UserSliderCode_channelSlider]
    }
    else if (sliderThatWasMoved == maxSlider)
    {
        //[UserSliderCode_maxSlider] -- add your slider handling code here..
      midizone->_max = sliderThatWasMoved->getValue();
        //[/UserSliderCode_maxSlider]
    }
    else if (sliderThatWasMoved == minSlider)
    {
        //[UserSliderCode_minSlider] -- add your slider handling code here..
      midizone->_min = sliderThatWasMoved->getValue();
        //[/UserSliderCode_minSlider]
    }
    else if (sliderThatWasMoved == Xslider)
    {
        //[UserSliderCode_Xslider] -- add your slider handling code here..
      midizone->_from_column = sliderThatWasMoved->getMinValue();
      midizone->_to_column = sliderThatWasMoved->getMaxValue();
        //[/UserSliderCode_Xslider]
    }
    else if (sliderThatWasMoved == Yslider)
    {
        //[UserSliderCode_Yslider] -- add your slider handling code here..
      midizone->_from_row = sliderThatWasMoved->getMinValue();
      midizone->_to_row = sliderThatWasMoved->getMaxValue();
        //[/UserSliderCode_Yslider]
    }
    else if (sliderThatWasMoved == dataSlider)
    {
        //[UserSliderCode_dataSlider] -- add your slider handling code here..
      midizone->_data1 = sliderThatWasMoved->getValue();
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
  <BACKGROUND backgroundColour="ffffffff"/>
  <COMBOBOX name="Type" id="c1f4660eabe8fccb" memberName="typeComboBox1"
            virtualName="" explicitFocusOrder="0" pos="96 0 88 24" editable="0"
            layout="33" items="Control Change&#10;Note On&#10;Pitch Bend&#10;NRPN&#10;Channel Pressure&#10;Polyphonic Aftertouch"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Type" id="c60683b64f639182" memberName="typeComboBox2"
            virtualName="" explicitFocusOrder="0" pos="96 32 88 24" editable="0"
            layout="33" items="Horizontal Slider&#10;Vertical Slider&#10;Momentary Button&#10;Toggle Button"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="channel" id="3b517834e41dae35" memberName="channelSlider"
          virtualName="" explicitFocusOrder="0" pos="192 0 32 56" min="1"
          max="16" int="1" style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="max" id="aa57fa59b0b89fff" memberName="maxSlider" virtualName=""
          explicitFocusOrder="0" pos="312 0 32 56" min="0" max="127" int="1"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="min" id="b0ac6409986e9469" memberName="minSlider" virtualName=""
          explicitFocusOrder="0" pos="272 0 32 56" min="0" max="127" int="1"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="X" id="9789276617163945" memberName="Xslider" virtualName=""
          explicitFocusOrder="0" pos="352 0 56 56" min="0" max="10" int="1"
          style="TwoValueHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Y" id="159851448f456c82" memberName="Yslider" virtualName=""
          explicitFocusOrder="0" pos="416 0 32 56" min="0" max="8" int="1"
          style="TwoValueVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="data" id="e3a29d8ffb183a23" memberName="dataSlider" virtualName=""
          explicitFocusOrder="0" pos="232 0 32 56" min="0" max="127" int="1"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Type" id="ee97d6a8e0e218c6" memberName="typeComboBox3"
            virtualName="" explicitFocusOrder="0" pos="0 32 88 24" editable="0"
            layout="33" items="Bar&#10;Fill&#10;Dot&#10;None" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
