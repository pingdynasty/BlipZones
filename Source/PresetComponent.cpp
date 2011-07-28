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

//[Headers] You can add your own extra header files here...
// #include <Math.h>
#include "BlipBox.h"
//[/Headers]

#include "PresetComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
uint8_t buf[1+4*8];
uint8_t bufpos;
//[/MiscUserDefs]

//==============================================================================
PresetComponent::PresetComponent ()
    : zoneComboBox (0),
      typeComboBox (0),
      Xslider (0),
      Yslider (0),
      channelSlider (0),
      data1Slider (0),
      sendButton (0),
      label (0),
      label2 (0),
      label3 (0),
      label4 (0),
      label5 (0),
      label6 (0),
      label7 (0),
      presetComboBox (0),
      showButton (0)
{
    addAndMakeVisible (zoneComboBox = new ComboBox (L"Zone"));
    zoneComboBox->setTooltip (L"Zone");
    zoneComboBox->setEditableText (false);
    zoneComboBox->setJustificationType (Justification::centredLeft);
    zoneComboBox->setTextWhenNothingSelected (String::empty);
    zoneComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    zoneComboBox->addItem (L"1", 1);
    zoneComboBox->addItem (L"2", 2);
    zoneComboBox->addItem (L"3", 3);
    zoneComboBox->addItem (L"4", 4);
    zoneComboBox->addItem (L"5", 5);
    zoneComboBox->addItem (L"6", 6);
    zoneComboBox->addItem (L"7", 7);
    zoneComboBox->addItem (L"8", 8);
    zoneComboBox->addListener (this);

    addAndMakeVisible (typeComboBox = new ComboBox (L"Type"));
    typeComboBox->setEditableText (false);
    typeComboBox->setJustificationType (Justification::centredLeft);
    typeComboBox->setTextWhenNothingSelected (String::empty);
    typeComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    typeComboBox->addItem (L"Horizontal CC Slider", 1);
    typeComboBox->addItem (L"Vertical CC Slider", 2);
    typeComboBox->addItem (L"Horizontal Note Player", 3);
    typeComboBox->addItem (L"Vertical Note Player", 4);
    typeComboBox->addItem (L"Note Push Button", 5);
    typeComboBox->addItem (L"Note Toggle Button", 6);
    typeComboBox->addItem (L"CC Push Button", 7);
    typeComboBox->addItem (L"CC Toggle Button", 8);
    typeComboBox->addItem (L"Inverted Horizontal CC Slider", 9);
    typeComboBox->addItem (L"Inverted Vertical CC Slider", 10);
//     typeComboBox->addItem (L"PRESET_BUTTON", 9);
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

    addAndMakeVisible (channelSlider = new Slider (L"Channel"));
    channelSlider->setRange (1, 16, 1);
    channelSlider->setSliderStyle (Slider::LinearHorizontal);
    channelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    channelSlider->addListener (this);

    addAndMakeVisible (data1Slider = new Slider (L"Data1"));
    data1Slider->setRange (0, 127, 1);
    data1Slider->setSliderStyle (Slider::LinearHorizontal);
    data1Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    data1Slider->addListener (this);

    addAndMakeVisible (sendButton = new TextButton (L"Send"));
    sendButton->setButtonText (L"send");
    sendButton->addButtonListener (this);

    addAndMakeVisible (label = new Label (L"new label",
                                          L"Channel"));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (L"new label",
                                           L"Data1"));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label3 = new Label (L"new label",
                                           L"Zone"));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label4 = new Label (L"new label",
                                           L"Type"));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label5 = new Label (L"new label",
                                           L"X"));
    label5->setFont (Font (15.0000f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label6 = new Label (L"new label",
                                           L"Y"));
    label6->setFont (Font (15.0000f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label7 = new Label (L"new label",
                                           L"Preset"));
    label7->setFont (Font (15.0000f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (presetComboBox = new ComboBox (L"Preset"));
    presetComboBox->setEditableText (false);
    presetComboBox->setJustificationType (Justification::centredLeft);
    presetComboBox->setTextWhenNothingSelected (String::empty);
    presetComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    presetComboBox->addItem (L"1", 1);
    presetComboBox->addItem (L"2", 2);
    presetComboBox->addItem (L"3", 3);
    presetComboBox->addItem (L"4", 4);
    presetComboBox->addItem (L"5", 5);
    presetComboBox->addListener (this);

    addAndMakeVisible (showButton = new TextButton (L"show button"));
    showButton->setButtonText (L"request");
    showButton->addButtonListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    init();
    //[/Constructor]
}

PresetComponent::~PresetComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (zoneComboBox);
    deleteAndZero (typeComboBox);
    deleteAndZero (Xslider);
    deleteAndZero (Yslider);
    deleteAndZero (channelSlider);
    deleteAndZero (data1Slider);
    deleteAndZero (sendButton);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (label3);
    deleteAndZero (label4);
    deleteAndZero (label5);
    deleteAndZero (label6);
    deleteAndZero (label7);
    deleteAndZero (presetComboBox);
    deleteAndZero (showButton);


    //[Destructor]. You can add your own custom destruction code here..
    release();
    //[/Destructor]
}

//==============================================================================
void PresetComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PresetComponent::resized()
{
    zoneComboBox->setBounds (8, 80, 150, 24);
    typeComboBox->setBounds (176, 80, 200, 24);
    Xslider->setBounds (8, 120, 240, 72);
    Yslider->setBounds (256, 144, 64, 136);
    channelSlider->setBounds (8, 240, 150, 24);
    data1Slider->setBounds (8, 304, 150, 24);
    sendButton->setBounds (200, 304, 152, 24);
    label->setBounds (8, 216, 150, 24);
    label2->setBounds (8, 280, 150, 24);
    label3->setBounds (8, 48, 150, 24);
    label4->setBounds (176, 48, 150, 24);
    label5->setBounds (120, 168, 24, 24);
    label6->setBounds (248, 200, 24, 24);
    label7->setBounds (104, 8, 54, 24);
    presetComboBox->setBounds (176, 8, 150, 24);
    showButton->setBounds (200, 344, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PresetComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == zoneComboBox)
    {
        //[UserComboBoxCode_zoneComboBox] -- add your combo box handling code here..
      std::cout << "zone " << zoneComboBox->getSelectedItemIndex() << std::endl;
      loadZone(comboBoxThatHasChanged->getSelectedItemIndex());
        //[/UserComboBoxCode_zoneComboBox]
    }
    else if (comboBoxThatHasChanged == typeComboBox)
    {
        //[UserComboBoxCode_typeComboBox] -- add your combo box handling code here..
      std::cout << "type " << typeComboBox->getText().toUTF8() << std::endl;
      getZone().setTypeIndex(typeComboBox->getSelectedItemIndex());
//       getZone()._type = preset->getTypeCode(typeComboBox->getSelectedItemIndex());
        //[/UserComboBoxCode_typeComboBox]
    }
    else if (comboBoxThatHasChanged == presetComboBox)
    {
        //[UserComboBoxCode_presetComboBox] -- add your combo box handling code here..
      loadPreset(comboBoxThatHasChanged->getSelectedItemIndex());
        //[/UserComboBoxCode_presetComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void PresetComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == Xslider)
    {
        //[UserSliderCode_Xslider] -- add your slider handling code here..
      getZone()._from_x = sliderThatWasMoved->getMinValue();
      getZone()._to_x = sliderThatWasMoved->getMaxValue();
        //[/UserSliderCode_Xslider]
    }
    else if (sliderThatWasMoved == Yslider)
    {
        //[UserSliderCode_Yslider] -- add your slider handling code here..
      getZone()._from_y = sliderThatWasMoved->getMinValue();
      getZone()._to_y = sliderThatWasMoved->getMaxValue();
        //[/UserSliderCode_Yslider]
    }
    else if (sliderThatWasMoved == channelSlider)
    {
        //[UserSliderCode_channelSlider] -- add your slider handling code here..
      getZone()._status = sliderThatWasMoved->getValue();
        //[/UserSliderCode_channelSlider]
    }
    else if (sliderThatWasMoved == data1Slider)
    {
        //[UserSliderCode_data1Slider] -- add your slider handling code here..
      getZone()._data1 = sliderThatWasMoved->getValue();
        //[/UserSliderCode_data1Slider]
    }

    //[UsersliderValueChanged_Post]
    if(sliderThatWasMoved == Xslider || sliderThatWasMoved == Yslider)
      blipbox->drawMidiZone(getZone());
    //[/UsersliderValueChanged_Post]
}

void PresetComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == sendButton)
    {
        //[UserButtonCode_sendButton] -- add your button handler code here..
      std::cout << "send!" << std::endl;
      blipbox->sendMidiZonePreset(*preset);
        //[/UserButtonCode_sendButton]
    }
    else if (buttonThatWasClicked == showButton)
    {
        //[UserButtonCode_showButton] -- add your button handler code here..
      std::cout << "request!" << std::endl;
      blipbox->requestMidiZonePreset(preset->getIndex());
      bufpos = 0;
//       blipbox->drawMidiZone(getZone());
      std::cout << "done!" << std::endl;
        //[/UserButtonCode_showButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void PresetComponent::init(){
  blipbox = new BlipBox(L"/dev/tty.usbserial-A60081hf");
  blipbox->setEventHandler(this);
  blipbox->connect();
  presetComboBox->setSelectedItemIndex(0, false);
  loadPreset(presetComboBox->getSelectedItemIndex());
}

void PresetComponent::handleReleaseMessage(){
//   loadZone(getZone());
}

void PresetComponent::handlePositionMessage(uint16_t x, uint16_t y){
  x = x*10/1023;
  y = y*8/1023;
  MidiZone zone = getZone();
  const MessageManagerLock mmLock;
  if(abs(zone._from_x - x) < abs(zone._to_x - x))
    Xslider->setMinValue(x, true);
  else
    Xslider->setMaxValue(x, true);
  if(abs(zone._from_y - y) < abs(zone._to_y - y))
    Yslider->setMinValue(y, true);
  else
    Yslider->setMaxValue(y, true);
}

void PresetComponent::handleParameterMessage(uint8_t pid, uint16_t value){
  std::cout << "preset ... [" << (int)pid << "] [" << (pid == 24) << "]" << std::endl;
  if(pid == 6){
    std::cout << "preset data " << (int)bufpos << std::endl;
    if(bufpos < sizeof(buf))
      buf[bufpos++] = (uint8_t)value;
    else
      std::cerr << "preset buffer overflow!" << std::endl;
    if(bufpos == sizeof(buf)){
      uint8_t index = buf[0];
      std::cout << "loading preset " << index << std::endl;
      preset = blipbox->getPreset(index);
      for(int i=0; i<8; ++i)
        preset->getZone(i).read(&buf[1+i*4]);
      loadPreset(index);
    }
  }
}

void PresetComponent::release(){
  if(blipbox != NULL)
    blipbox->disconnect();
  delete blipbox;
}
MidiZone& PresetComponent::getZone(){
  return preset->getZone(zoneComboBox->getSelectedItemIndex());
}
void PresetComponent::loadPreset(uint8_t index){
  preset = blipbox->getPreset(index);
  /*       if(index < MIDI_ZONE_PRESETS) */
  /* 	preset = &presets[index]; */
  zoneComboBox->setSelectedItemIndex(0, false);
  loadZone(zoneComboBox->getSelectedItemIndex());
}
void PresetComponent::loadZone(uint8_t index){
  MidiZone& zone = preset->getZone(index);
  loadZone(zone);
}
void PresetComponent::loadZone(MidiZone& zone){
  typeComboBox->setSelectedItemIndex(zone.getTypeIndex(), false);
  channelSlider->setValue(zone.getChannel(), false);
  data1Slider->setValue(zone._data1, false);
  Xslider->setMinValue(zone._from_x, false);
  Yslider->setMinValue(zone._from_y, false);
  Xslider->setMaxValue(zone._to_x, false);
  Yslider->setMaxValue(zone._to_y, false);
  blipbox->drawMidiZone(getZone());
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PresetComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <COMBOBOX name="Zone" id="849f27102424c1ef" memberName="zoneComboBox" virtualName=""
            explicitFocusOrder="0" pos="8 80 150 24" tooltip="Zone" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Type" id="c1f4660eabe8fccb" memberName="typeComboBox" virtualName=""
            explicitFocusOrder="0" pos="176 80 150 24" editable="0" layout="33"
            items="HORIZONTAL_CC&#10;VERTICAL_CC&#13; HORIZONTAL_NOTE&#10;VERTICAL_NOTE&#10;NOTE_PUSH_BUTTON&#10;NOTE_TOGGLE_BUTTON&#10;CC_PUSH_BUTTON&#10;CC_TOGGLE_BUTTON&#10;PRESET_BUTTON"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="X" id="9789276617163945" memberName="Xslider" virtualName=""
          explicitFocusOrder="0" pos="8 120 240 72" min="0" max="10" int="1"
          style="TwoValueHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Y" id="159851448f456c82" memberName="Yslider" virtualName=""
          explicitFocusOrder="0" pos="256 144 64 136" min="0" max="8" int="1"
          style="TwoValueVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Channel" id="4c70fabed7653844" memberName="channelSlider"
          virtualName="" explicitFocusOrder="0" pos="8 240 150 24" min="1"
          max="16" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Data1" id="b3ac5e4363e75e3f" memberName="data1Slider" virtualName=""
          explicitFocusOrder="0" pos="8 304 150 24" min="0" max="127" int="1"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Send" id="13dae98d24a6df1f" memberName="sendButton" virtualName=""
              explicitFocusOrder="0" pos="200 304 152 24" buttonText="send"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="c264c37dc008364a" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 216 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Channel" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="17c7f974e00ad03f" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 280 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Data1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="66e377d43bde1d6" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 48 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Zone" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a3738382892f760d" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="176 48 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5f34daa1df4747fe" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="120 168 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="X" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="4e0224ecad4ec6dc" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="248 200 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Y" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="500d6335007480ac" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="104 8 54 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Preset" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="Preset" id="95a22405f5cfbfc2" memberName="presetComboBox"
            virtualName="" explicitFocusOrder="0" pos="176 8 150 24" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4&#10;5" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="show button" id="6d5630b830980a64" memberName="showButton"
              virtualName="" explicitFocusOrder="0" pos="200 344 150 24" buttonText="show"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
