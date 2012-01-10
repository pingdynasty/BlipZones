/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  9 Jan 2012 11:11:08pm

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
#include "MidiControllerComponent.h"
#include "MidiPitchBendComponent.h"
#include "MidiNoteComponent.h"
#include "MidiConstants.h"
//[/Headers]

#include "ZoneComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
const bool dontSendChangeMessage = true;
const bool sendUpdateMessage = false;
const bool sendMessageSynchronously = true;
const bool allowNudgingOfOtherValues = true;
//[/MiscUserDefs]

//==============================================================================
ZoneComponent::ZoneComponent ()
    : Component (L"Zone"),
      component (0),
      typeComboBox (0),
      Xslider (0),
      Yslider (0),
      typeComboBox2 (0),
      typeComboBox3 (0)
{
    addAndMakeVisible (component = new ActionComponent());
    addAndMakeVisible (typeComboBox = new ComboBox (L"Type"));
    typeComboBox->setEditableText (false);
    typeComboBox->setJustificationType (Justification::centredLeft);
    typeComboBox->setTextWhenNothingSelected (String::empty);
    typeComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    typeComboBox->addItem (L"Control Change", 1);
    typeComboBox->addItem (L"Note On", 2);
    typeComboBox->addItem (L"Pitch Bend", 3);
    typeComboBox->addItem (L"NRPN", 4);
    typeComboBox->addItem (L"Channel Pressure", 5);
    typeComboBox->addItem (L"Polyphonic Aftertouch", 6);
    typeComboBox->addItem (L"Select Preset", 7);
    typeComboBox->addListener (this);

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

    addAndMakeVisible (typeComboBox2 = new ComboBox (L"Type"));
    typeComboBox2->setEditableText (false);
    typeComboBox2->setJustificationType (Justification::centredLeft);
    typeComboBox2->setTextWhenNothingSelected (String::empty);
    typeComboBox2->setTextWhenNoChoicesAvailable (L"(no choices)");
    typeComboBox2->addItem (L"Horizontal Slider", 1);
    typeComboBox2->addItem (L"Vertical Slider", 2);
    typeComboBox2->addItem (L"Momentary Button", 3);
    typeComboBox2->addItem (L"Toggle Button", 4);
    typeComboBox2->addItem (L"Disabled", 5);
    typeComboBox2->addListener (this);

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
    //[/Constructor]
}

ZoneComponent::~ZoneComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (component);
    deleteAndZero (typeComboBox);
    deleteAndZero (Xslider);
    deleteAndZero (Yslider);
    deleteAndZero (typeComboBox2);
    deleteAndZero (typeComboBox3);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ZoneComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xf5f9ea0));
    g.fillRoundedRectangle (1.0f, 4.0f, 510.0f, 70.0f, 3.5000f);

    g.setColour (Colours::cadetblue);
    g.drawRoundedRectangle (1.0f, 4.0f, 510.0f, 70.0f, 3.5000f, 0.5000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ZoneComponent::resized()
{
    component->setBounds (0, 0, 512, 72);
    typeComboBox->setBounds (192, 8, 136, 24);
    Xslider->setBounds (8, 40, 136, 32);
    Yslider->setBounds (152, 0, 32, 72);
    typeComboBox2->setBounds (8, 8, 136, 24);
    typeComboBox3->setBounds (328 - 136, 40, 136, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ZoneComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == typeComboBox)
    {
        //[UserComboBoxCode_typeComboBox] -- add your combo box handling code here..
      std::cout << "selected " << typeComboBox->getSelectedId() << std::endl;
      delete zone->action;
      switch(typeComboBox->getSelectedId()){
      case 1:
	zone->action = Action::createAction(MIDI_CONTROL_CHANGE);
	break;
      case 2:
	zone->action = Action::createAction(MIDI_NOTE_ON);
	break;
      case 3:
	zone->action = Action::createAction(MIDI_PITCH_BEND);
	break;
      case 4: // NRPN - todo!
	zone->action = Action::createAction(MIDI_NRPN_ACTION_TYPE);
	break;
      case 5:
	zone->action = Action::createAction(MIDI_CHANNEL_PRESSURE);
	break;
      case 6:
	zone->action = Action::createAction(MIDI_AFTERTOUCH);
	break;
      case 7:
	zone->action = Action::createAction(SELECT_PRESET_ACTION_TYPE);
	break;
      default:
	zone->action = Action::createAction(0);
	break;
      }
      loadAction(zone->action);
        //[/UserComboBoxCode_typeComboBox]
    }
    else if (comboBoxThatHasChanged == typeComboBox2)
    {
        //[UserComboBoxCode_typeComboBox2] -- add your combo box handling code here..
      uint8_t from = zone->from.getValue();
      uint8_t to = zone->to.getValue();
      typeComboBox->setVisible(true);
      typeComboBox3->setVisible(true);
      switch(typeComboBox2->getSelectedId()){
      case 1:
	zone->setZoneType(HORIZONTAL_SLIDER_ZONE_TYPE);
	break;
      case 2:
	zone->setZoneType(VERTICAL_SLIDER_ZONE_TYPE);
	break;
      case 3:
	zone->setZoneType(MOMENTARY_BUTTON_ZONE_TYPE);
	break;
      case 4:
	zone->setZoneType(TOGGLE_BUTTON_ZONE_TYPE);
	break;
      case 5:
      default:
	zone->setZoneType(DISABLED_ZONE_TYPE);
	typeComboBox->setVisible(false);
	typeComboBox3->setVisible(false);
      }
      zone->from.setValue(from);
      zone->to.setValue(to);
        //[/UserComboBoxCode_typeComboBox2]
    }
    else if (comboBoxThatHasChanged == typeComboBox3)
    {
        //[UserComboBoxCode_typeComboBox3] -- add your combo box handling code here..
      switch(typeComboBox3->getSelectedId()){
      case 1:
	zone->setDisplayType(LINE_DISPLAY_TYPE);
	break;
      case 2:
	zone->setDisplayType(FILL_DISPLAY_TYPE);
	break;
      case 3:
      default:
	zone->setDisplayType(NONE_DISPLAY_TYPE);
	break;
      }
        //[/UserComboBoxCode_typeComboBox3]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ZoneComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == Xslider)
    {
        //[UserSliderCode_Xslider] -- add your slider handling code here..
      zone->from.setColumn(Xslider->getMinValue());
      zone->to.setColumn(Xslider->getMaxValue());
        //[/UserSliderCode_Xslider]
    }
    else if (sliderThatWasMoved == Yslider)
    {
        //[UserSliderCode_Yslider] -- add your slider handling code here..
      zone->from.setRow(Yslider->getMinValue());
      zone->to.setRow(Yslider->getMaxValue());
        //[/UserSliderCode_Yslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// void ZoneComponent::createActionComponent(uint8_t type){
//   deleteAndZero(component);
//   switch(type & MIDI_STATUS_MASK){
//   case MIDI_CONTROL_CHANGE:
//     component = new MidiControllerComponent();
//     break;
//   default:
//     component = new ActionComponent();
//     break;
//   }
//   addAndMakeVisible(component);
//   component->setBounds (0, 0, 512, 72);
//   component->toBack();
//   component->loadAction(zone->action);
// }

void ZoneComponent::loadZone(Zone* azone){
  // we just change our pointer: the zone is contained in a preset.
  zone = azone;
  std::cout << "loading zone" << std::endl;
  Xslider->setMinValue(zone->from.getColumn(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Yslider->setMinValue(zone->from.getRow(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Xslider->setMaxValue(zone->to.getColumn(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Yslider->setMaxValue(zone->to.getRow(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Xslider->setMinValue(zone->from.getColumn(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Yslider->setMinValue(zone->from.getRow(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);

  typeComboBox->setVisible(true);
  typeComboBox3->setVisible(true);

  switch(zone->getZoneType()){
  case HORIZONTAL_SLIDER_ZONE_TYPE:
    typeComboBox2->setSelectedId(1, dontSendChangeMessage);
    break;
  case VERTICAL_SLIDER_ZONE_TYPE:
    typeComboBox2->setSelectedId(2, dontSendChangeMessage);
    break;
  case MOMENTARY_BUTTON_ZONE_TYPE:
    typeComboBox2->setSelectedId(3, dontSendChangeMessage);
    break;
  case TOGGLE_BUTTON_ZONE_TYPE:
    typeComboBox2->setSelectedId(4, dontSendChangeMessage);
    break;
  case DISABLED_ZONE_TYPE:
  default:
    typeComboBox2->setSelectedId(5, dontSendChangeMessage);
    typeComboBox->setVisible(false);
    typeComboBox3->setVisible(false);
  }
  switch(zone->getDisplayType()){
  case LINE_DISPLAY_TYPE:
    typeComboBox3->setSelectedId(1);
    break;
  case FILL_DISPLAY_TYPE:
    typeComboBox3->setSelectedId(2);
    break;
  case NONE_DISPLAY_TYPE:
  default:
    typeComboBox3->setSelectedId(3);
  }
  loadAction(zone->action);
}

void ZoneComponent::loadAction(Action* action){
  deleteAndZero(component);
  if(action == NULL){
    component = new ActionComponent();
  }else{
    switch(action->getType() & MIDI_STATUS_MASK){
    case MIDI_CONTROL_CHANGE:
      component = new MidiControllerComponent();
      typeComboBox->setSelectedId(1, dontSendChangeMessage);
      break;
    case MIDI_NOTE_ON:
    case MIDI_NOTE_OFF:
      component = new MidiNoteComponent();
      typeComboBox->setSelectedId(2, dontSendChangeMessage);
      break;
    case MIDI_PITCH_BEND:
      component = new MidiPitchBendComponent();
      typeComboBox->setSelectedId(3, dontSendChangeMessage);
      break;
    default:
      component = new ActionComponent();
      typeComboBox->setText(String::empty, dontSendChangeMessage);
      break;
    }
    component->loadAction(action);
  }
  addAndMakeVisible(component);
  component->setBounds(0, 0, 512, 72);
  component->toBack();
}

void ZoneComponent::handlePositionMessage(uint16_t x, uint16_t y){
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

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ZoneComponent" componentName="Zone"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="100">
  <BACKGROUND backgroundColour="ffffffff">
    <ROUNDRECT pos="1 4 510 70" cornerSize="3.5" fill="solid: f5f9ea0" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff5f9ea0"/>
  </BACKGROUND>
  <JUCERCOMP name="" id="8433e26c9d51226f" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 0 512 72" sourceFile="ActionComponent.cpp"
             constructorParams=""/>
  <COMBOBOX name="Type" id="c1f4660eabe8fccb" memberName="typeComboBox" virtualName=""
            explicitFocusOrder="0" pos="192 8 136 24" editable="0" layout="33"
            items="Control Change&#10;Note On&#10;Pitch Bend&#10;NRPN&#10;Channel Pressure&#10;Polyphonic Aftertouch&#10;Select Preset"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="X" id="9789276617163945" memberName="Xslider" virtualName=""
          explicitFocusOrder="0" pos="8 40 136 32" min="0" max="10" int="1"
          style="TwoValueHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Y" id="159851448f456c82" memberName="Yslider" virtualName=""
          explicitFocusOrder="0" pos="152 0 32 72" min="0" max="8" int="1"
          style="TwoValueVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Type" id="c60683b64f639182" memberName="typeComboBox2"
            virtualName="" explicitFocusOrder="0" pos="8 8 136 24" editable="0"
            layout="33" items="Horizontal Slider&#10;Vertical Slider&#10;Momentary Button&#10;Toggle Button&#10;Disabled"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Type" id="ee97d6a8e0e218c6" memberName="typeComboBox3"
            virtualName="" explicitFocusOrder="0" pos="328r 40 136 24" editable="0"
            layout="33" items="Bar&#10;Fill&#10;Dot&#10;None" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
