/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  5 Nov 2011 9:20:33am

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
#include "MidiMessageReceiver.h"
#include "BlipClient.h"
//[/Headers]

#include "ApplicationSettingsComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ApplicationSettingsComponent::ApplicationSettingsComponent ()
    : label (0),
      connectButton (0),
      label2 (0),
      serialSpeedComboBox (0),
      okButton (0),
      presetDirectoryEditor (0),
      label3 (0),
      cancelButton (0),
      label4 (0),
      midiInputComboBox (0),
      serialPortComboBox (0),
      label5 (0),
      midiOutputComboBox (0)
{
    addAndMakeVisible (label = new Label (L"new label",
                                          L"Serial Port"));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (connectButton = new TextButton (L"new button"));
    connectButton->setButtonText (L"connect");
    connectButton->addListener (this);

    addAndMakeVisible (label2 = new Label (L"new label",
                                           L"Serial Speed"));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (serialSpeedComboBox = new ComboBox (L"new combo box"));
    serialSpeedComboBox->setEditableText (false);
    serialSpeedComboBox->setJustificationType (Justification::centredLeft);
    serialSpeedComboBox->setTextWhenNothingSelected (String::empty);
    serialSpeedComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    serialSpeedComboBox->addItem (L"9600", 1);
    serialSpeedComboBox->addItem (L"19200", 2);
    serialSpeedComboBox->addItem (L"38400", 3);
    serialSpeedComboBox->addItem (L"57600", 4);
    serialSpeedComboBox->addItem (L"115200", 5);
    serialSpeedComboBox->addListener (this);

    addAndMakeVisible (okButton = new TextButton (L"new button"));
    okButton->setButtonText (L"ok");
    okButton->setConnectedEdges (Button::ConnectedOnRight);
    okButton->addListener (this);

    addAndMakeVisible (presetDirectoryEditor = new TextEditor (L"new text editor"));
    presetDirectoryEditor->setMultiLine (false);
    presetDirectoryEditor->setReturnKeyStartsNewLine (false);
    presetDirectoryEditor->setReadOnly (false);
    presetDirectoryEditor->setScrollbarsShown (true);
    presetDirectoryEditor->setCaretVisible (true);
    presetDirectoryEditor->setPopupMenuEnabled (true);
    presetDirectoryEditor->setText (String::empty);

    addAndMakeVisible (label3 = new Label (L"new label",
                                           L"Preset Directory"));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (cancelButton = new TextButton (L"new button"));
    cancelButton->setButtonText (L"cancel");
    cancelButton->setConnectedEdges (Button::ConnectedOnLeft);
    cancelButton->addListener (this);

    addAndMakeVisible (label4 = new Label (L"new label",
                                           L"MIDI Input"));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (midiInputComboBox = new ComboBox (L"new combo box"));
    midiInputComboBox->setEditableText (false);
    midiInputComboBox->setJustificationType (Justification::centredLeft);
    midiInputComboBox->setTextWhenNothingSelected (String::empty);
    midiInputComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    midiInputComboBox->addListener (this);

    addAndMakeVisible (serialPortComboBox = new ComboBox (L"new combo box"));
    serialPortComboBox->setEditableText (true);
    serialPortComboBox->setJustificationType (Justification::centredLeft);
    serialPortComboBox->setTextWhenNothingSelected (String::empty);
    serialPortComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    serialPortComboBox->addListener (this);

    addAndMakeVisible (label5 = new Label (L"new label",
                                           L"MIDI Output"));
    label5->setFont (Font (15.0000f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (midiOutputComboBox = new ComboBox (L"new combo box"));
    midiOutputComboBox->setEditableText (false);
    midiOutputComboBox->setJustificationType (Justification::centredLeft);
    midiOutputComboBox->setTextWhenNothingSelected (String::empty);
    midiOutputComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    midiOutputComboBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 240);


    //[Constructor] You can add your own custom stuff here..

    loadSettingsFromFile();

    //[/Constructor]
}

ApplicationSettingsComponent::~ApplicationSettingsComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (label);
    deleteAndZero (connectButton);
    deleteAndZero (label2);
    deleteAndZero (serialSpeedComboBox);
    deleteAndZero (okButton);
    deleteAndZero (presetDirectoryEditor);
    deleteAndZero (label3);
    deleteAndZero (cancelButton);
    deleteAndZero (label4);
    deleteAndZero (midiInputComboBox);
    deleteAndZero (serialPortComboBox);
    deleteAndZero (label5);
    deleteAndZero (midiOutputComboBox);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ApplicationSettingsComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ApplicationSettingsComponent::resized()
{
    label->setBounds (16, 16, 104, 24);
    connectButton->setBounds (392, 16, 80, 24);
    label2->setBounds (16, 48, 104, 24);
    serialSpeedComboBox->setBounds (128, 48, 256, 24);
    okButton->setBounds (200 - ((80) / 2), getHeight() - 44, 80, 24);
    presetDirectoryEditor->setBounds (128, 80, 256, 24);
    label3->setBounds (16, 80, 104, 24);
    cancelButton->setBounds (280 - ((80) / 2), getHeight() - 44, 80, 24);
    label4->setBounds (16, 112, 104, 24);
    midiInputComboBox->setBounds (128, 112, 256, 24);
    serialPortComboBox->setBounds (128, 16, 256, 24);
    label5->setBounds (16, 152, 104, 24);
    midiOutputComboBox->setBounds (128, 152, 256, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ApplicationSettingsComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == connectButton)
    {
        //[UserButtonCode_connectButton] -- add your button handler code here..
      ApplicationConfiguration::getBlipClient()->disconnect();
//       std::cout << "checking connection " << ApplicationConfiguration::getBlipClient()->getPort() << std::endl;
//       if(ApplicationConfiguration::getBlipClient()->isConnected()){
// 	if(ApplicationConfiguration::getBlipClient()->checkConnection()){
// 	  std::cout << "checked connection " << ApplicationConfiguration::getBlipClient()->getPort() << std::endl;
// 	  ApplicationConfiguration::getBlipClient()->disconnect();
// 	}else{
// 	  std::cout << "fake connection " << ApplicationConfiguration::getBlipClient()->getPort() << std::endl;
// 	}
//       }
      String port = serialPortComboBox->getText();
      String speed = serialSpeedComboBox->getText();
      ApplicationConfiguration::getBlipClient()->setPort(port);
      ApplicationConfiguration::getBlipClient()->setSpeed(speed.getIntValue());
      ApplicationConfiguration::getBlipClient()->connect();
      std::cout << "connect pressed " << ApplicationConfiguration::getBlipClient()->isConnected() << std::endl;
        //[/UserButtonCode_connectButton]
    }
    else if (buttonThatWasClicked == okButton)
    {
        //[UserButtonCode_okButton] -- add your button handler code here..
      saveSettingsToFile();
      setVisible(false);
      DialogWindow* dw = findParentComponentOfClass((DialogWindow*)nullptr);
      if(dw != nullptr)
	dw->exitModalState(1);
      std::cout << "ok pressed" << std::endl;
        //[/UserButtonCode_okButton]
    }
    else if (buttonThatWasClicked == cancelButton)
    {
        //[UserButtonCode_cancelButton] -- add your button handler code here..
      setVisible(false);
      DialogWindow* dw = findParentComponentOfClass((DialogWindow*)nullptr);
      if(dw != nullptr)
	dw->exitModalState(0);
      std::cout << "cancel pressed" << std::endl;
        //[/UserButtonCode_cancelButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ApplicationSettingsComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == serialSpeedComboBox)
    {
        //[UserComboBoxCode_serialSpeedComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_serialSpeedComboBox]
    }
    else if (comboBoxThatHasChanged == midiInputComboBox)
    {
        //[UserComboBoxCode_midiInputComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiInputComboBox]
    }
    else if (comboBoxThatHasChanged == serialPortComboBox)
    {
        //[UserComboBoxCode_serialPortComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_serialPortComboBox]
    }
    else if (comboBoxThatHasChanged == midiOutputComboBox)
    {
        //[UserComboBoxCode_midiOutputComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiOutputComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

int ApplicationSettingsComponent::showModalDialog(Component* ref){
  return DialogWindow::showModalDialog
    ("Application Settings", this, ref, Colours::lightgrey, true, true, true);
}

void ApplicationSettingsComponent::loadSettingsFromFile(){
  PropertiesFile* properties = ApplicationConfiguration::getApplicationProperties();
#if JUCE_MAC || JUCE_IOS
  DirectoryIterator it(File("/dev"), false, "tty.usbserial-*");
#elif JUCE_WINDOWS
  DirectoryIterator it(File("\\\\.\\"), false, "COM*");
#elif JUCE_LINUX
  DirectoryIterator it(File("/dev"), false, "ttyUSB*");
#endif
  int index = 1;
  serialPortComboBox->addItem("none", index);
  while(it.next())
    serialPortComboBox->addItem(it.getFile().getFullPathName(), ++index);
  serialPortComboBox->setText(properties->getValue("serialport"));
  serialSpeedComboBox->setText(properties->getValue("serialspeed"));
  presetDirectoryEditor->setText(properties->getValue("presetdirectory"));

  const StringArray& inputs = MidiInput::getDevices();
  midiInputComboBox->addItem("none", ++index);
  for(int i=0; i<inputs.size(); ++i)
    midiInputComboBox->addItem(inputs[i], ++index);
#if ! JUCE_WINDOWS
  midiInputComboBox->addItem("BlipZones", ++index);
#endif
  midiInputComboBox->setText(properties->getValue("midiinput"));

  const StringArray& outputs = MidiOutput::getDevices();
  midiOutputComboBox->addItem("none", ++index);
  for(int i=0; i<outputs.size(); ++i)
    midiOutputComboBox->addItem(outputs[i], ++index);
#if ! JUCE_WINDOWS
  midiOutputComboBox->addItem("BlipZones", ++index);
#endif
  midiOutputComboBox->setText(properties->getValue("midioutput"));

  std::cout << "loaded settings from file " << properties->getFile().getFullPathName() << std::endl;
}

void ApplicationSettingsComponent::saveSettingsToFile(){
  PropertiesFile* properties = ApplicationConfiguration::getApplicationProperties();
  properties->setValue("serialport", serialPortComboBox->getText());
  properties->setValue("serialspeed", serialSpeedComboBox->getText());
  properties->setValue("presetdirectory", presetDirectoryEditor->getText());
  properties->setValue("midiinput", midiInputComboBox->getText());
  properties->setValue("midioutput", midiOutputComboBox->getText());
  properties->saveIfNeeded();
  std::cout << "saved settings to file " << properties->getFile().getFullPathName() << std::endl;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ApplicationSettingsComponent"
                 componentName="" parentClasses="public Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330000013" fixedSize="0" initialWidth="600"
                 initialHeight="240">
  <BACKGROUND backgroundColour="ffffffff"/>
  <LABEL name="new label" id="20e8eb8f34814ba6" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 16 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Serial Port" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="9b952ca3de910c42" memberName="connectButton"
              virtualName="" explicitFocusOrder="0" pos="392 16 80 24" buttonText="connect"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="daf6ce893988c58" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="16 48 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Serial Speed" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="a1108fbb9604f6d3" memberName="serialSpeedComboBox"
            virtualName="" explicitFocusOrder="0" pos="128 48 256 24" editable="0"
            layout="33" items="9600&#10;19200&#10;38400&#10;57600&#10;115200"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="27a3a467f58abccc" memberName="okButton"
              virtualName="" explicitFocusOrder="0" pos="200c 44R 80 24" buttonText="ok"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="27a835615731286b" memberName="presetDirectoryEditor"
              virtualName="" explicitFocusOrder="0" pos="128 80 256 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="d6b33339b8006d84" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="16 80 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Preset Directory" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="d0d47bce2a4f1493" memberName="cancelButton"
              virtualName="" explicitFocusOrder="0" pos="280c 44R 80 24" buttonText="cancel"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="7d1479c64375a3e1" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="16 112 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="MIDI Input" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="409c99a536e1b8d5" memberName="midiInputComboBox"
            virtualName="" explicitFocusOrder="0" pos="128 112 256 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="77110bc32a931265" memberName="serialPortComboBox"
            virtualName="" explicitFocusOrder="0" pos="128 16 256 24" editable="1"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="60d65c9746810e9a" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="16 152 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="MIDI Output" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="3652bf1f65dcab20" memberName="midiOutputComboBox"
            virtualName="" explicitFocusOrder="0" pos="128 152 256 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
