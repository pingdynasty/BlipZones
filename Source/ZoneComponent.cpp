/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  2 Feb 2012 4:29:51pm

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
#include "MidiNoteRangeComponent.h"
#include "SelectPresetComponent.h"
#include "ControlVoltageComponent.h"
#include "OscComponent.h"
#include "MidiConstants.h"
#include "PresetFactory.h"
//[/Headers]

#include "ZoneComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
const bool dontSendChangeMessage = true;
const bool sendUpdateMessage = false;
const bool sendMessageSynchronously = true;
const bool allowNudgingOfOtherValues = true;
//[/MiscUserDefs]

//==============================================================================
ZoneComponent::ZoneComponent (Zone* z)
    : zone(z),
      component (0),
      actionTypeComboBox (0),
      Xslider (0),
      Yslider (0),
      displayTypeComboBox (0),
      typeLabel (0),
      deleteButton (0)
{
    addAndMakeVisible (component = new ActionComponent());
    addAndMakeVisible (actionTypeComboBox = new ComboBox (L"Action Type"));
    actionTypeComboBox->setEditableText (false);
    actionTypeComboBox->setJustificationType (Justification::centredLeft);
    actionTypeComboBox->setTextWhenNothingSelected (String::empty);
    actionTypeComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    actionTypeComboBox->addItem (L"Control Change", 1);
    actionTypeComboBox->addItem (L"Note On", 2);
    actionTypeComboBox->addItem (L"Pitch Bend", 3);
    actionTypeComboBox->addItem (L"Channel Pressure", 4);
    actionTypeComboBox->addItem (L"Polyphonic Aftertouch", 5);
    actionTypeComboBox->addItem (L"Note Range", 6);
    actionTypeComboBox->addItem (L"NRPN", 7);
    actionTypeComboBox->addItem (L"Select Preset", 8);
    actionTypeComboBox->addItem (L"Control Voltage", 9);
    actionTypeComboBox->addItem (L"OSC", 10);
    actionTypeComboBox->addListener (this);

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

    addAndMakeVisible (displayTypeComboBox = new ComboBox (L"Display Type"));
    displayTypeComboBox->setEditableText (false);
    displayTypeComboBox->setJustificationType (Justification::centredLeft);
    displayTypeComboBox->setTextWhenNothingSelected (String::empty);
    displayTypeComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    displayTypeComboBox->addItem (L"Bar", 1);
    displayTypeComboBox->addItem (L"Fill", 2);
    displayTypeComboBox->addItem (L"None", 3);
    displayTypeComboBox->addListener (this);

    addAndMakeVisible (typeLabel = new Label (L"Type Label",
                                              L"Zone Type"));
    typeLabel->setFont (Font (15.0000f, Font::plain));
    typeLabel->setJustificationType (Justification::centredLeft);
    typeLabel->setEditable (false, false, false);
    typeLabel->setColour (TextEditor::textColourId, Colours::black);
    typeLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (deleteButton = new ImageButton (L"delete button"));
    deleteButton->setButtonText (L"delete");
    deleteButton->addListener (this);

    deleteButton->setImages (false, true, true,
                             ImageCache::getFromMemory (deleteButtonSmall_png, deleteButtonSmall_pngSize), 1.0000f, Colour (0x0),
                             Image(), 1.0000f, Colour (0x0),
                             Image(), 1.0000f, Colour (0x0));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 100);


    //[Constructor] You can add your own custom stuff here..
    loadZone(zone);
//     loadZone(Zone::createZone(DISABLED_ZONE_TYPE));
    //[/Constructor]
}

ZoneComponent::~ZoneComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (component);
    deleteAndZero (actionTypeComboBox);
    deleteAndZero (Xslider);
    deleteAndZero (Yslider);
    deleteAndZero (displayTypeComboBox);
    deleteAndZero (typeLabel);
    deleteAndZero (deleteButton);


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
    actionTypeComboBox->setBounds (192, 8, 136, 24);
    Xslider->setBounds (8, 40, 136, 32);
    Yslider->setBounds (152, 0, 32, 72);
    displayTypeComboBox->setBounds (328 - 136, 40, 136, 24);
    typeLabel->setBounds (32, 8, 112, 24);
    deleteButton->setBounds (8, 8, 23, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ZoneComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == actionTypeComboBox)
    {
        //[UserComboBoxCode_actionTypeComboBox] -- add your combo box handling code here..
      Action* action = PresetFactory::createAction(actionTypeComboBox->getText());
      loadAction(action);
      zone->action = action;
        //[/UserComboBoxCode_actionTypeComboBox]
    }
    else if (comboBoxThatHasChanged == displayTypeComboBox)
    {
        //[UserComboBoxCode_displayTypeComboBox] -- add your combo box handling code here..
      switch(displayTypeComboBox->getSelectedId()){
      case 1:
	zone->setDisplayType(LINE_DISPLAY_TYPE);
	break;
      case 2:
	zone->setDisplayType(FILL_DISPLAY_TYPE);
	break;
      case 3:
	zone->setDisplayType(NONE_DISPLAY_TYPE);
	break;
      }
        //[/UserComboBoxCode_displayTypeComboBox]
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

void ZoneComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == deleteButton)
    {
        //[UserButtonCode_deleteButton] -- add your button handler code here..

      // todo!
//       ApplicationConfiguration::getBlipSim()->getPreset()->;

        //[/UserButtonCode_deleteButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void ZoneComponent::setZoneType(ZoneType type){
  // todo: remove if not used
//   uint8_t from = zone->from.getValue();
//   uint8_t to = zone->to.getValue();
//   Action* action = zone->action;
//   delete zone;
//   zone = Zone::createZone(type);
//   zone->from.setValue(from);
//   zone->to.setValue(to);
//   zone->action = action;
}

void ZoneComponent::loadZone(Zone* z){
  std::cout << "loading zone" << std::endl;
  if(z == NULL)
    return;
  // we just change our pointer: the zone is contained in a preset.
  zone = z;
  Xslider->setMinValue(zone->from.getColumn(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Yslider->setMinValue(zone->from.getRow(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Xslider->setMaxValue(zone->to.getColumn(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Yslider->setMaxValue(zone->to.getRow(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Xslider->setMinValue(zone->from.getColumn(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);
  Yslider->setMinValue(zone->from.getRow(), sendUpdateMessage, sendMessageSynchronously, allowNudgingOfOtherValues);

  actionTypeComboBox->setVisible(true);
  displayTypeComboBox->setVisible(true);
  switch(zone->getZoneType()){
  case HORIZONTAL_SLIDER_ZONE_TYPE:
    typeLabel->setText("Horizontal Slider", false);
    break;
  case VERTICAL_SLIDER_ZONE_TYPE:
    typeLabel->setText("Vertical Slider", false);
    break;
  case MOMENTARY_BUTTON_ZONE_TYPE:
    typeLabel->setText("Momentary Button", false);
    break;
  case TOGGLE_BUTTON_ZONE_TYPE:
    typeLabel->setText("Toggle Button", false);
    break;
  case DISABLED_ZONE_TYPE:
  default:
    actionTypeComboBox->setVisible(false);
    displayTypeComboBox->setVisible(false);
  }

  switch(zone->getDisplayType()){
  case LINE_DISPLAY_TYPE:
    displayTypeComboBox->setSelectedId(1);
    break;
  case FILL_DISPLAY_TYPE:
    displayTypeComboBox->setSelectedId(2);
    break;
  case NONE_DISPLAY_TYPE:
  default:
    displayTypeComboBox->setSelectedId(3);
  }
  loadAction(zone->action);
}

void ZoneComponent::loadAction(Action* action){
  deleteAndZero(component);
  if(action == NULL){
    component = new ActionComponent();
  }else{
    switch(action->getActionType()){
    case MIDI_CONTROL_CHANGE:
      component = new MidiControllerComponent();
      actionTypeComboBox->setSelectedId(1, dontSendChangeMessage);
      break;
    case MIDI_NOTE_ON:
    case MIDI_NOTE_OFF:
      component = new MidiNoteComponent();
      actionTypeComboBox->setSelectedId(2, dontSendChangeMessage);
      break;
    case MIDI_PITCH_BEND:
      component = new MidiPitchBendComponent();
      actionTypeComboBox->setSelectedId(3, dontSendChangeMessage);
      break;
//     case MIDI_CHANNEL_PRESSURE:
//        component = new MidiChannelPressureComponent();
//       actionTypeComboBox->setSelectedId(4, dontSendChangeMessage);
//       break;
//     case MIDI_AFTERTOUCH:
//        component = new MidiAftertouchComponent();
//       actionTypeComboBox->setSelectedId(5, dontSendChangeMessage);
//       break;
    case MIDI_NOTE_RANGE_ACTION_TYPE:
      component = new MidiNoteRangeComponent();
      actionTypeComboBox->setSelectedId(6, dontSendChangeMessage);
      break;
//     case MIDI_NRPN_ACTION_TYPE:
//        component = new MidiNRPNComponent();
//       actionTypeComboBox->setSelectedId(7, dontSendChangeMessage);
//       break;
    case SELECT_PRESET_ACTION_TYPE:
      component = new SelectPresetComponent();
      actionTypeComboBox->setSelectedId(8, dontSendChangeMessage);
      break;
    case CONTROL_VOLTAGE_ACTION_TYPE:
       component = new ControlVoltageComponent();
      actionTypeComboBox->setSelectedId(9, dontSendChangeMessage);
      break;
    case OSC_ACTION_TYPE:
      component = new OscComponent();
      actionTypeComboBox->setText(T("OSC"), dontSendChangeMessage);
      break;
    default:
      component = new ActionComponent();
      actionTypeComboBox->setText(T("Unavailable"), dontSendChangeMessage);
      break;
    }
    component->loadAction(action);
  }
  addAndMakeVisible(component);
  component->setBounds(0, 0, 512, 72);
  component->toBack();
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ZoneComponent" componentName=""
                 parentClasses="public Component" constructorParams="Zone* z"
                 variableInitialisers="zone(z)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330000013" fixedSize="0" initialWidth="600"
                 initialHeight="100">
  <BACKGROUND backgroundColour="ffffffff">
    <ROUNDRECT pos="1 4 510 70" cornerSize="3.5" fill="solid: f5f9ea0" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff5f9ea0"/>
  </BACKGROUND>
  <JUCERCOMP name="" id="8433e26c9d51226f" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 0 512 72" sourceFile="ActionComponent.cpp"
             constructorParams=""/>
  <COMBOBOX name="Action Type" id="c1f4660eabe8fccb" memberName="actionTypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="192 8 136 24" editable="0"
            layout="33" items="Control Change&#10;Note On&#10;Pitch Bend&#10;Channel Pressure&#10;Polyphonic Aftertouch&#10;Note Range&#10;NRPN&#10;Select Preset&#10;Control Voltage&#10;OSC"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="X" id="9789276617163945" memberName="Xslider" virtualName=""
          explicitFocusOrder="0" pos="8 40 136 32" min="0" max="10" int="1"
          style="TwoValueHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Y" id="159851448f456c82" memberName="Yslider" virtualName=""
          explicitFocusOrder="0" pos="152 0 32 72" min="0" max="8" int="1"
          style="TwoValueVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Display Type" id="ee97d6a8e0e218c6" memberName="displayTypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="328r 40 136 24" editable="0"
            layout="33" items="Bar&#10;Fill&#10;None" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="Type Label" id="cc644bbdf1e40c7f" memberName="typeLabel"
         virtualName="" explicitFocusOrder="0" pos="32 8 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Zone Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <IMAGEBUTTON name="delete button" id="12ad1bce5b170b59" memberName="deleteButton"
               virtualName="" explicitFocusOrder="0" pos="8 8 23 24" buttonText="delete"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="deleteButtonSmall_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown=""
               opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: deleteButtonSmall_png, 3992, "../Resources/DeleteButtonSmall.png"
static const unsigned char resource_ZoneComponent_deleteButtonSmall_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,9,112,72,89,115,0,0,11,19,
0,0,11,19,1,0,154,156,24,0,0,10,79,105,67,67,80,80,104,111,116,111,115,104,111,112,32,73,67,67,32,112,114,111,102,105,108,101,0,0,120,218,157,83,103,84,83,233,22,61,247,222,244,66,75,136,128,148,75,111,
82,21,8,32,82,66,139,128,20,145,38,42,33,9,16,74,136,33,161,217,21,81,193,17,69,69,4,27,200,160,136,3,142,142,128,140,21,81,44,12,138,10,216,7,228,33,162,142,131,163,136,138,202,251,225,123,163,107,214,
188,247,230,205,254,181,215,62,231,172,243,157,179,207,7,192,8,12,150,72,51,81,53,128,12,169,66,30,17,224,131,199,196,198,225,228,46,64,129,10,36,112,0,16,8,179,100,33,115,253,35,1,0,248,126,60,60,43,
34,192,7,190,0,1,120,211,11,8,0,192,77,155,192,48,28,135,255,15,234,66,153,92,1,128,132,1,192,116,145,56,75,8,128,20,0,64,122,142,66,166,0,64,70,1,128,157,152,38,83,0,160,4,0,96,203,99,98,227,0,80,45,
0,96,39,127,230,211,0,128,157,248,153,123,1,0,91,148,33,21,1,160,145,0,32,19,101,136,68,0,104,59,0,172,207,86,138,69,0,88,48,0,20,102,75,196,57,0,216,45,0,48,73,87,102,72,0,176,183,0,192,206,16,11,178,
0,8,12,0,48,81,136,133,41,0,4,123,0,96,200,35,35,120,0,132,153,0,20,70,242,87,60,241,43,174,16,231,42,0,0,120,153,178,60,185,36,57,69,129,91,8,45,113,7,87,87,46,30,40,206,73,23,43,20,54,97,2,97,154,64,
46,194,121,153,25,50,129,52,15,224,243,204,0,0,160,145,21,17,224,131,243,253,120,206,14,174,206,206,54,142,182,14,95,45,234,191,6,255,34,98,98,227,254,229,207,171,112,64,0,0,225,116,126,209,254,44,47,
179,26,128,59,6,128,109,254,162,37,238,4,104,94,11,160,117,247,139,102,178,15,64,181,0,160,233,218,87,243,112,248,126,60,60,69,161,144,185,217,217,229,228,228,216,74,196,66,91,97,202,87,125,254,103,194,
95,192,87,253,108,249,126,60,252,247,245,224,190,226,36,129,50,93,129,71,4,248,224,194,204,244,76,165,28,207,146,9,132,98,220,230,143,71,252,183,11,255,252,29,211,34,196,73,98,185,88,42,20,227,81,18,113,
142,68,154,140,243,50,165,34,137,66,146,41,197,37,210,255,100,226,223,44,251,3,62,223,53,0,176,106,62,1,123,145,45,168,93,99,3,246,75,39,16,88,116,192,226,247,0,0,242,187,111,193,212,40,8,3,128,104,131,
225,207,119,255,239,63,253,71,160,37,0,128,102,73,146,113,0,0,94,68,36,46,84,202,179,63,199,8,0,0,68,160,129,42,176,65,27,244,193,24,44,192,6,28,193,5,220,193,11,252,96,54,132,66,36,196,194,66,16,66,10,
100,128,28,114,96,41,172,130,66,40,134,205,176,29,42,96,47,212,64,29,52,192,81,104,134,147,112,14,46,194,85,184,14,61,112,15,250,97,8,158,193,40,188,129,9,4,65,200,8,19,97,33,218,136,1,98,138,88,35,142,
8,23,153,133,248,33,193,72,4,18,139,36,32,201,136,20,81,34,75,145,53,72,49,82,138,84,32,85,72,29,242,61,114,2,57,135,92,70,186,145,59,200,0,50,130,252,134,188,71,49,148,129,178,81,61,212,12,181,67,185,
168,55,26,132,70,162,11,208,100,116,49,154,143,22,160,155,208,114,180,26,61,140,54,161,231,208,171,104,15,218,143,62,67,199,48,192,232,24,7,51,196,108,48,46,198,195,66,177,56,44,9,147,99,203,177,34,172,
12,171,198,26,176,86,172,3,187,137,245,99,207,177,119,4,18,129,69,192,9,54,4,119,66,32,97,30,65,72,88,76,88,78,216,72,168,32,28,36,52,17,218,9,55,9,3,132,81,194,39,34,147,168,75,180,38,186,17,249,196,
24,98,50,49,135,88,72,44,35,214,18,143,19,47,16,123,136,67,196,55,36,18,137,67,50,39,185,144,2,73,177,164,84,210,18,210,70,210,110,82,35,233,44,169,155,52,72,26,35,147,201,218,100,107,178,7,57,148,44,
32,43,200,133,228,157,228,195,228,51,228,27,228,33,242,91,10,157,98,64,113,164,248,83,226,40,82,202,106,74,25,229,16,229,52,229,6,101,152,50,65,85,163,154,82,221,168,161,84,17,53,143,90,66,173,161,182,
82,175,81,135,168,19,52,117,154,57,205,131,22,73,75,165,173,162,149,211,26,104,23,104,247,105,175,232,116,186,17,221,149,30,78,151,208,87,210,203,233,71,232,151,232,3,244,119,12,13,134,21,131,199,136,
103,40,25,155,24,7,24,103,25,119,24,175,152,76,166,25,211,139,25,199,84,48,55,49,235,152,231,153,15,153,111,85,88,42,182,42,124,21,145,202,10,149,74,149,38,149,27,42,47,84,169,170,166,170,222,170,11,85,
243,85,203,84,143,169,94,83,125,174,70,85,51,83,227,169,9,212,150,171,85,170,157,80,235,83,27,83,103,169,59,168,135,170,103,168,111,84,63,164,126,89,253,137,6,89,195,76,195,79,67,164,81,160,177,95,227,
188,198,32,11,99,25,179,120,44,33,107,13,171,134,117,129,53,196,38,177,205,217,124,118,42,187,152,253,29,187,139,61,170,169,161,57,67,51,74,51,87,179,82,243,148,102,63,7,227,152,113,248,156,116,78,9,231,
40,167,151,243,126,138,222,20,239,41,226,41,27,166,52,76,185,49,101,92,107,170,150,151,150,88,171,72,171,81,171,71,235,189,54,174,237,167,157,166,189,69,187,89,251,129,14,65,199,74,39,92,39,71,103,143,
206,5,157,231,83,217,83,221,167,10,167,22,77,61,58,245,174,46,170,107,165,27,161,187,68,119,191,110,167,238,152,158,190,94,128,158,76,111,167,222,121,189,231,250,28,125,47,253,84,253,109,250,167,245,71,
12,88,6,179,12,36,6,219,12,206,24,60,197,53,113,111,60,29,47,199,219,241,81,67,93,195,64,67,165,97,149,97,151,225,132,145,185,209,60,163,213,70,141,70,15,140,105,198,92,227,36,227,109,198,109,198,163,
38,6,38,33,38,75,77,234,77,238,154,82,77,185,166,41,166,59,76,59,76,199,205,204,205,162,205,214,153,53,155,61,49,215,50,231,155,231,155,215,155,223,183,96,90,120,90,44,182,168,182,184,101,73,178,228,90,
166,89,238,182,188,110,133,90,57,89,165,88,85,90,93,179,70,173,157,173,37,214,187,173,187,167,17,167,185,78,147,78,171,158,214,103,195,176,241,182,201,182,169,183,25,176,229,216,6,219,174,182,109,182,
125,97,103,98,23,103,183,197,174,195,238,147,189,147,125,186,125,141,253,61,7,13,135,217,14,171,29,90,29,126,115,180,114,20,58,86,58,222,154,206,156,238,63,125,197,244,150,233,47,103,88,207,16,207,216,
51,227,182,19,203,41,196,105,157,83,155,211,71,103,23,103,185,115,131,243,136,139,137,75,130,203,46,151,62,46,155,27,198,221,200,189,228,74,116,245,113,93,225,122,210,245,157,155,179,155,194,237,168,219,
175,238,54,238,105,238,135,220,159,204,52,159,41,158,89,51,115,208,195,200,67,224,81,229,209,63,11,159,149,48,107,223,172,126,79,67,79,129,103,181,231,35,47,99,47,145,87,173,215,176,183,165,119,170,247,
97,239,23,62,246,62,114,159,227,62,227,60,55,222,50,222,89,95,204,55,192,183,200,183,203,79,195,111,158,95,133,223,67,127,35,255,100,255,122,255,209,0,167,128,37,1,103,3,137,129,65,129,91,2,251,248,122,
124,33,191,142,63,58,219,101,246,178,217,237,65,140,160,185,65,21,65,143,130,173,130,229,193,173,33,104,200,236,144,173,33,247,231,152,206,145,206,105,14,133,80,126,232,214,208,7,97,230,97,139,195,126,
12,39,133,135,133,87,134,63,142,112,136,88,26,209,49,151,53,119,209,220,67,115,223,68,250,68,150,68,222,155,103,49,79,57,175,45,74,53,42,62,170,46,106,60,218,55,186,52,186,63,198,46,102,89,204,213,88,
157,88,73,108,75,28,57,46,42,174,54,110,108,190,223,252,237,243,135,226,157,226,11,227,123,23,152,47,200,93,112,121,161,206,194,244,133,167,22,169,46,18,44,58,150,64,76,136,78,56,148,240,65,16,42,168,
22,140,37,242,19,119,37,142,10,121,194,29,194,103,34,47,209,54,209,136,216,67,92,42,30,78,242,72,42,77,122,146,236,145,188,53,121,36,197,51,165,44,229,185,132,39,169,144,188,76,13,76,221,155,58,158,22,
154,118,32,109,50,61,58,189,49,131,146,145,144,113,66,170,33,77,147,182,103,234,103,230,102,118,203,172,101,133,178,254,197,110,139,183,47,30,149,7,201,107,179,144,172,5,89,45,10,182,66,166,232,84,90,
40,215,42,7,178,103,101,87,102,191,205,137,202,57,150,171,158,43,205,237,204,179,202,219,144,55,156,239,159,255,237,18,194,18,225,146,182,165,134,75,87,45,29,88,230,189,172,106,57,178,60,113,121,219,10,
227,21,5,43,134,86,6,172,60,184,138,182,42,109,213,79,171,237,87,151,174,126,189,38,122,77,107,129,94,193,202,130,193,181,1,107,235,11,85,10,229,133,125,235,220,215,237,93,79,88,47,89,223,181,97,250,134,
157,27,62,21,137,138,174,20,219,23,151,21,127,216,40,220,120,229,27,135,111,202,191,153,220,148,180,169,171,196,185,100,207,102,210,102,233,230,222,45,158,91,14,150,170,151,230,151,14,110,13,217,218,180,
13,223,86,180,237,245,246,69,219,47,151,205,40,219,187,131,182,67,185,163,191,60,184,188,101,167,201,206,205,59,63,84,164,84,244,84,250,84,54,238,210,221,181,97,215,248,110,209,238,27,123,188,246,52,236,
213,219,91,188,247,253,62,201,190,219,85,1,85,77,213,102,213,101,251,73,251,179,247,63,174,137,170,233,248,150,251,109,93,173,78,109,113,237,199,3,210,3,253,7,35,14,182,215,185,212,213,29,210,61,84,82,
143,214,43,235,71,14,199,31,190,254,157,239,119,45,13,54,13,85,141,156,198,226,35,112,68,121,228,233,247,9,223,247,30,13,58,218,118,140,123,172,225,7,211,31,118,29,103,29,47,106,66,154,242,154,70,155,
83,154,251,91,98,91,186,79,204,62,209,214,234,222,122,252,71,219,31,15,156,52,60,89,121,74,243,84,201,105,218,233,130,211,147,103,242,207,140,157,149,157,125,126,46,249,220,96,219,162,182,123,231,99,206,
223,106,15,111,239,186,16,116,225,210,69,255,139,231,59,188,59,206,92,242,184,116,242,178,219,229,19,87,184,87,154,175,58,95,109,234,116,234,60,254,147,211,79,199,187,156,187,154,174,185,92,107,185,238,
122,189,181,123,102,247,233,27,158,55,206,221,244,189,121,241,22,255,214,213,158,57,61,221,189,243,122,111,247,197,247,245,223,22,221,126,114,39,253,206,203,187,217,119,39,238,173,188,79,188,95,244,64,
237,65,217,67,221,135,213,63,91,254,220,216,239,220,127,106,192,119,160,243,209,220,71,247,6,133,131,207,254,145,245,143,15,67,5,143,153,143,203,134,13,134,235,158,56,62,57,57,226,63,114,253,233,252,167,
67,207,100,207,38,158,23,254,162,254,203,174,23,22,47,126,248,213,235,215,206,209,152,209,161,151,242,151,147,191,109,124,165,253,234,192,235,25,175,219,198,194,198,30,190,201,120,51,49,94,244,86,251,
237,193,119,220,119,29,239,163,223,15,79,228,124,32,127,40,255,104,249,177,245,83,208,167,251,147,25,147,147,255,4,3,152,243,252,99,51,45,219,0,0,0,32,99,72,82,77,0,0,122,37,0,0,128,131,0,0,249,255,0,
0,128,233,0,0,117,48,0,0,234,96,0,0,58,152,0,0,23,111,146,95,197,70,0,0,4,195,73,68,65,84,120,218,196,215,109,76,27,117,0,199,241,223,245,184,182,199,21,66,187,66,161,144,236,129,58,165,24,164,83,131,
195,135,140,205,119,227,153,110,75,96,185,100,175,106,66,156,104,136,162,84,151,40,15,213,45,42,51,18,251,130,145,49,222,241,74,163,91,66,96,24,31,152,68,29,106,132,194,198,224,21,165,56,70,70,184,210,
167,112,127,95,208,54,109,185,94,203,102,226,37,247,174,247,255,126,218,222,253,239,255,167,8,33,248,95,143,36,0,106,164,185,37,19,0,245,31,36,146,142,69,8,129,66,234,130,43,77,214,50,29,203,206,143,52,
183,156,5,64,63,70,156,30,105,110,57,171,99,217,249,43,77,214,50,41,68,34,128,234,175,171,47,47,202,206,30,3,80,164,101,217,129,225,211,103,248,71,68,208,195,167,207,240,90,150,29,0,80,84,148,157,61,214,
95,87,95,158,136,80,196,197,107,106,203,77,57,57,163,52,160,135,40,130,18,69,38,159,227,156,195,214,83,123,69,208,195,214,83,124,62,199,57,41,81,100,32,138,160,1,189,41,39,103,180,191,166,54,14,161,136,
198,171,107,202,139,181,218,81,5,69,233,9,33,136,156,32,132,49,104,52,206,107,77,214,116,17,244,181,38,43,111,208,104,156,32,132,137,29,75,65,81,250,98,173,118,180,191,186,38,138,136,0,84,121,28,119,65,
1,232,137,40,34,241,132,40,50,6,142,115,14,53,52,166,66,208,67,13,141,188,129,227,156,16,69,70,106,44,5,160,207,227,184,11,0,84,177,128,140,182,27,215,47,46,111,108,204,72,93,20,139,184,90,223,144,12,
65,95,173,111,144,141,19,81,196,242,198,198,76,219,141,235,23,1,100,0,0,69,8,1,69,81,74,0,5,250,204,204,35,31,159,120,181,187,48,43,171,36,233,99,11,132,60,130,96,59,247,205,215,67,0,182,35,241,193,218,
58,62,95,163,113,82,0,147,236,218,229,205,77,215,59,227,99,157,107,91,91,183,1,172,16,66,130,17,0,5,64,9,192,168,207,204,180,56,142,85,117,165,66,172,10,130,237,220,119,223,14,1,192,224,201,106,222,144,
70,188,227,251,9,251,218,214,214,52,0,55,128,32,33,132,68,0,8,223,20,59,8,150,181,56,142,85,117,25,53,26,89,196,138,32,188,6,0,5,26,205,87,114,113,183,32,236,196,125,190,104,124,103,30,34,136,5,236,66,
244,190,252,74,42,196,118,248,34,90,46,254,238,143,63,236,138,71,102,194,68,192,46,68,247,139,47,201,34,228,14,183,32,184,58,127,254,73,50,46,7,136,71,168,89,75,87,101,101,151,145,227,246,132,112,123,
189,46,251,228,164,125,205,47,29,79,5,136,67,236,83,171,45,31,85,188,144,54,194,237,245,186,222,159,250,197,254,192,239,79,26,79,7,176,11,113,233,104,229,229,28,165,178,80,46,254,48,24,92,110,191,53,121,
62,85,92,238,109,152,112,159,33,8,96,181,213,92,122,40,139,166,13,162,40,66,238,204,162,105,67,171,185,244,16,128,85,185,120,244,27,166,248,5,0,128,254,242,104,37,159,199,178,178,207,121,226,35,250,143,
207,103,107,189,53,25,59,89,225,81,254,2,250,139,138,10,62,79,157,126,60,14,225,247,217,94,159,154,74,138,72,5,160,47,63,247,60,159,167,86,239,57,30,143,240,219,206,255,246,171,36,66,14,64,247,29,121,
150,207,77,17,95,241,249,22,0,160,128,101,77,114,136,251,126,191,237,141,219,191,239,66,36,3,208,159,151,91,248,92,149,74,54,238,241,251,93,31,206,206,124,2,0,31,152,75,223,206,87,171,101,167,237,251,
129,128,173,237,143,233,56,132,20,128,254,172,236,153,180,226,221,243,115,246,245,96,112,6,0,116,74,101,105,231,147,79,117,165,131,120,243,175,63,163,136,68,0,253,105,233,211,169,227,129,128,171,231,206,
29,251,122,40,24,121,206,1,192,168,99,148,150,247,14,31,238,202,87,169,82,34,222,154,249,123,8,192,118,44,128,190,100,54,243,185,202,212,113,199,194,93,251,122,40,20,59,201,32,50,89,233,24,198,210,97,
122,34,53,34,24,176,181,207,206,14,17,66,182,163,75,50,136,164,74,110,37,227,241,249,164,226,36,102,178,114,175,135,66,211,142,133,187,118,143,207,231,146,91,89,65,36,85,137,75,50,69,251,156,171,111,94,
216,28,151,140,251,125,46,199,226,61,169,120,226,140,185,131,88,188,103,247,248,165,17,243,194,230,120,251,156,171,47,210,142,0,2,0,86,122,22,23,123,231,188,194,68,236,74,214,19,8,184,28,75,75,114,113,
105,196,210,146,221,19,8,184,98,199,154,243,10,19,61,139,139,189,0,86,194,205,184,173,25,3,192,8,224,68,199,254,3,55,7,75,204,196,81,108,154,213,50,76,35,128,131,225,159,44,157,173,26,21,254,236,65,45,
195,52,58,138,77,179,131,37,102,210,177,255,192,77,0,39,194,13,38,218,78,216,27,70,16,199,109,198,194,1,29,195,212,237,49,190,11,161,99,152,58,155,177,112,0,192,241,216,184,220,68,196,0,216,7,32,7,192,
38,128,181,116,222,106,50,175,114,61,128,44,0,15,1,60,0,16,138,219,24,39,217,29,211,225,111,144,241,152,59,100,42,60,134,74,106,47,65,8,193,191,3,0,88,141,69,118,30,136,249,181,0,0,0,0,73,69,78,68,174,
66,96,130,0,0};

const char* ZoneComponent::deleteButtonSmall_png = (const char*) resource_ZoneComponent_deleteButtonSmall_png;
const int ZoneComponent::deleteButtonSmall_pngSize = 3992;
