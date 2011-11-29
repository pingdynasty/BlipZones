/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  28 Nov 2011 10:45:07pm

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
#include "ApplicationConfiguration.h"
#include "ApplicationSettingsComponent.h"
#include "ZoneAreaAnimator.h"
//[/Headers]

#include "PresetComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
const bool useNativeVersion = false;

//[/MiscUserDefs]

//==============================================================================
PresetComponent::PresetComponent ()
    : zone8 (0),
      zone7 (0),
      zone6 (0),
      zone5 (0),
      zone4 (0),
      zone3 (0),
      zone2 (0),
      sendButton (0),
      label7 (0),
      presetComboBox (0),
      requestButton (0),
      zone1 (0),
      toggleButton1 (0),
      toggleButton2 (0),
      toggleButton3 (0),
      toggleButton4 (0),
      toggleButton5 (0),
      toggleButton6 (0),
      toggleButton7 (0),
      toggleButton8 (0),
      saveButton (0),
      loadButton (0),
      settingsButton (0),
      runButton (0)
{
    addAndMakeVisible (zone8 = new ZoneComponent());
    addAndMakeVisible (zone7 = new ZoneComponent());
    addAndMakeVisible (zone6 = new ZoneComponent());
    addAndMakeVisible (zone5 = new ZoneComponent());
    addAndMakeVisible (zone4 = new ZoneComponent());
    addAndMakeVisible (zone3 = new ZoneComponent());
    addAndMakeVisible (zone2 = new ZoneComponent());
    addAndMakeVisible (sendButton = new TextButton (L"send"));
    sendButton->setConnectedEdges (Button::ConnectedOnRight);
    sendButton->addListener (this);

    addAndMakeVisible (label7 = new Label (L"new label",
                                           L"Preset"));
    label7->setFont (Font (15.0000f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (presetComboBox = new ComboBox (L"Preset"));
    presetComboBox->setExplicitFocusOrder (10);
    presetComboBox->setEditableText (false);
    presetComboBox->setJustificationType (Justification::centredLeft);
    presetComboBox->setTextWhenNothingSelected (String::empty);
    presetComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    presetComboBox->addItem (L"1", 1);
    presetComboBox->addItem (L"2", 2);
    presetComboBox->addItem (L"3", 3);
    presetComboBox->addItem (L"4", 4);
    presetComboBox->addItem (L"5", 5);
    presetComboBox->addItem (L"6", 6);
    presetComboBox->addItem (L"7", 7);
    presetComboBox->addItem (L"8", 8);
    presetComboBox->addListener (this);

    addAndMakeVisible (requestButton = new TextButton (L"request button"));
    requestButton->setButtonText (L"request");
    requestButton->setConnectedEdges (Button::ConnectedOnLeft);
    requestButton->addListener (this);

    addAndMakeVisible (zone1 = new ZoneComponent());
    addAndMakeVisible (toggleButton1 = new ToggleButton (L"new toggle button"));
    toggleButton1->setExplicitFocusOrder (1);
    toggleButton1->setButtonText (L"1");
    toggleButton1->setRadioGroupId (1005);
    toggleButton1->addListener (this);

    addAndMakeVisible (toggleButton2 = new ToggleButton (L"new toggle button"));
    toggleButton2->setExplicitFocusOrder (2);
    toggleButton2->setButtonText (L"2");
    toggleButton2->setRadioGroupId (1005);
    toggleButton2->addListener (this);

    addAndMakeVisible (toggleButton3 = new ToggleButton (L"new toggle button"));
    toggleButton3->setExplicitFocusOrder (3);
    toggleButton3->setButtonText (L"3");
    toggleButton3->setRadioGroupId (1005);
    toggleButton3->addListener (this);

    addAndMakeVisible (toggleButton4 = new ToggleButton (L"new toggle button"));
    toggleButton4->setExplicitFocusOrder (4);
    toggleButton4->setButtonText (L"4");
    toggleButton4->setRadioGroupId (1005);
    toggleButton4->addListener (this);

    addAndMakeVisible (toggleButton5 = new ToggleButton (L"new toggle button"));
    toggleButton5->setExplicitFocusOrder (5);
    toggleButton5->setButtonText (L"5");
    toggleButton5->setRadioGroupId (1005);
    toggleButton5->addListener (this);

    addAndMakeVisible (toggleButton6 = new ToggleButton (L"new toggle button"));
    toggleButton6->setExplicitFocusOrder (6);
    toggleButton6->setButtonText (L"6");
    toggleButton6->setRadioGroupId (1005);
    toggleButton6->addListener (this);

    addAndMakeVisible (toggleButton7 = new ToggleButton (L"new toggle button"));
    toggleButton7->setExplicitFocusOrder (7);
    toggleButton7->setButtonText (L"7");
    toggleButton7->setRadioGroupId (1005);
    toggleButton7->addListener (this);

    addAndMakeVisible (toggleButton8 = new ToggleButton (L"new toggle button"));
    toggleButton8->setExplicitFocusOrder (8);
    toggleButton8->setButtonText (L"8");
    toggleButton8->setRadioGroupId (1005);
    toggleButton8->addListener (this);

    addAndMakeVisible (saveButton = new TextButton (L"save button"));
    saveButton->setButtonText (L"save");
    saveButton->setConnectedEdges (Button::ConnectedOnRight);
    saveButton->addListener (this);

    addAndMakeVisible (loadButton = new TextButton (L"load button"));
    loadButton->setButtonText (L"load");
    loadButton->setConnectedEdges (Button::ConnectedOnLeft);
    loadButton->addListener (this);

    addAndMakeVisible (settingsButton = new TextButton (L"reset"));
    settingsButton->setButtonText (L"settings");
    settingsButton->addListener (this);

    addAndMakeVisible (runButton = new ToggleButton (L"new toggle button"));
    runButton->setExplicitFocusOrder (9);
    runButton->setButtonText (L"run");
    runButton->setRadioGroupId (1005);
    runButton->addListener (this);
    runButton->setToggleState (true, false);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 700);


    //[Constructor] You can add your own custom stuff here..
    preset = new Preset();
    initialise();
    //[/Constructor]
}

PresetComponent::~PresetComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (zone8);
    deleteAndZero (zone7);
    deleteAndZero (zone6);
    deleteAndZero (zone5);
    deleteAndZero (zone4);
    deleteAndZero (zone3);
    deleteAndZero (zone2);
    deleteAndZero (sendButton);
    deleteAndZero (label7);
    deleteAndZero (presetComboBox);
    deleteAndZero (requestButton);
    deleteAndZero (zone1);
    deleteAndZero (toggleButton1);
    deleteAndZero (toggleButton2);
    deleteAndZero (toggleButton3);
    deleteAndZero (toggleButton4);
    deleteAndZero (toggleButton5);
    deleteAndZero (toggleButton6);
    deleteAndZero (toggleButton7);
    deleteAndZero (toggleButton8);
    deleteAndZero (saveButton);
    deleteAndZero (loadButton);
    deleteAndZero (settingsButton);
    deleteAndZero (runButton);


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
    zone8->setBounds (80, 568, 512, 72);
    zone7->setBounds (80, 496, 512, 72);
    zone6->setBounds (80, 424, 512, 72);
    zone5->setBounds (80, 352, 512, 72);
    zone4->setBounds (80, 280, 512, 72);
    zone3->setBounds (80, 208, 512, 72);
    zone2->setBounds (80, 136, 512, 72);
    sendButton->setBounds (392, 648, 80, 24);
    label7->setBounds (344, 8, 54, 24);
    presetComboBox->setBounds (400, 8, 150, 24);
    requestButton->setBounds (472, 648, 80, 24);
    zone1->setBounds (80, 64, 512, 72);
    toggleButton1->setBounds (48, 72, 32, 24);
    toggleButton2->setBounds (48, 144, 32, 24);
    toggleButton3->setBounds (48, 216, 32, 24);
    toggleButton4->setBounds (48, 288, 32, 24);
    toggleButton5->setBounds (48, 360, 32, 24);
    toggleButton6->setBounds (48, 432, 32, 24);
    toggleButton7->setBounds (48, 504, 32, 24);
    toggleButton8->setBounds (48, 576, 32, 24);
    saveButton->setBounds (120, 648, 80, 24);
    loadButton->setBounds (200, 648, 80, 24);
    settingsButton->setBounds (296, 648, 80, 24);
    runButton->setBounds (48, 648, 64, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PresetComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == sendButton)
    {
        //[UserButtonCode_sendButton] -- add your button handler code here..
      sendPreset();
        //[/UserButtonCode_sendButton]
    }
    else if (buttonThatWasClicked == requestButton)
    {
        //[UserButtonCode_requestButton] -- add your button handler code here..
      requestPreset();
        //[/UserButtonCode_requestButton]
    }
    else if (buttonThatWasClicked == toggleButton1)
    {
        //[UserButtonCode_toggleButton1] -- add your button handler code here..
      selectZone(1);
        //[/UserButtonCode_toggleButton1]
    }
    else if (buttonThatWasClicked == toggleButton2)
    {
        //[UserButtonCode_toggleButton2] -- add your button handler code here..
      selectZone(2);
        //[/UserButtonCode_toggleButton2]
    }
    else if (buttonThatWasClicked == toggleButton3)
    {
        //[UserButtonCode_toggleButton3] -- add your button handler code here..
      selectZone(3);
        //[/UserButtonCode_toggleButton3]
    }
    else if (buttonThatWasClicked == toggleButton4)
    {
        //[UserButtonCode_toggleButton4] -- add your button handler code here..
      selectZone(4);
        //[/UserButtonCode_toggleButton4]
    }
    else if (buttonThatWasClicked == toggleButton5)
    {
        //[UserButtonCode_toggleButton5] -- add your button handler code here..
      selectZone(5);
        //[/UserButtonCode_toggleButton5]
    }
    else if (buttonThatWasClicked == toggleButton6)
    {
        //[UserButtonCode_toggleButton6] -- add your button handler code here..
      selectZone(6);
        //[/UserButtonCode_toggleButton6]
    }
    else if (buttonThatWasClicked == toggleButton7)
    {
        //[UserButtonCode_toggleButton7] -- add your button handler code here..
      selectZone(7);
        //[/UserButtonCode_toggleButton7]
    }
    else if (buttonThatWasClicked == toggleButton8)
    {
        //[UserButtonCode_toggleButton8] -- add your button handler code here..
      selectZone(8);
        //[/UserButtonCode_toggleButton8]
    }
    else if (buttonThatWasClicked == saveButton)
    {
        //[UserButtonCode_saveButton] -- add your button handler code here..
      saveFile();
        //[/UserButtonCode_saveButton]
    }
    else if (buttonThatWasClicked == loadButton)
    {
        //[UserButtonCode_loadButton] -- add your button handler code here..
      loadFile();
        //[/UserButtonCode_loadButton]
    }
    else if (buttonThatWasClicked == settingsButton)
    {
        //[UserButtonCode_settingsButton] -- add your button handler code here..
      openSettings();
        //[/UserButtonCode_settingsButton]
    }
    else if (buttonThatWasClicked == runButton)
    {
        //[UserButtonCode_runButton] -- add your button handler code here..
      selectZone(0);
        //[/UserButtonCode_runButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PresetComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == presetComboBox)
    {
        //[UserComboBoxCode_presetComboBox] -- add your combo box handling code here..
      savePreset(ApplicationConfiguration::getBlipSim()->getPresetIndex());
      loadPreset(comboBoxThatHasChanged->getSelectedItemIndex());
        //[/UserComboBoxCode_presetComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// class PresetSynchronizingHackThread : public Thread {
// private:
//   PresetComponent* presetcomponent;
// public:
//   PresetSynchronizingHackThread(PresetComponent* pc) :
//     Thread(T("PresetSynchronizingHackThread")), presetcomponent(pc) {
//     setPriority(0);
//   }
//   void run(){
//     sleep(2000);
//     while(!threadShouldExit()){
//       const MessageManagerLock mmLock;
//       uint8_t index = ApplicationConfiguration::getBlipSim()->getPresetIndex();
//       if(presetcomponent->getPreset() != NULL &&
// 	 index != presetcomponent->getPreset()->getIndex()){
// 	presetcomponent->loadPreset(index);
//       }
//       sleep(200);
//     }
//     delete this;
//   }
// };

// PresetComponent* pchack;
void PresetComponent::initialise(){
  presetComboBox->setSelectedItemIndex(0, false);
  components.add(zone1);
  components.add(zone2);
  components.add(zone3);
  components.add(zone4);
  components.add(zone5);
  components.add(zone6);
  components.add(zone7);
  components.add(zone8);
  loadPreset(presetComboBox->getSelectedItemIndex());
//   PresetSynchronizingHackThread* hack = new PresetSynchronizingHackThread(this);
//   hack->startThread();
//   pchack = this;
}

// void MidiZonePreset::loadPreset(uint8_t index){
//   std::cout << "MidiZonePreset::loadPreset " << (int)index << std::endl;
//   const MessageManagerLock mmLock;
//   pchack->loadPreset(index);
// }

void PresetComponent::release(){
}

Preset* PresetComponent::getPreset(){
  return preset;
}

void PresetComponent::sendPreset(){
  std::cout << "send!" << std::endl;
  if(ApplicationConfiguration::getBlipClient()->isConnected()){
    ApplicationConfiguration::getBlipClient()->sendPreset(presetComboBox->getSelectedItemIndex());
    std::cout << "sent!" << std::endl;
  }else{
    AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
				     "Connection Error",
				     "BlipBox not connected!");
  }
}

void PresetComponent::openSettings(){
  std::cout << "opening settings" << std::endl;
  ApplicationSettingsComponent component;
  component.showModalDialog(this);
  std::cout << "settings done" << std::endl;
}

void PresetComponent::requestPreset(){
  std::cout << "request!" << std::endl;
  if(ApplicationConfiguration::getBlipClient()->isConnected()){
    ApplicationConfiguration::getBlipClient()->requestPreset(presetComboBox->getSelectedItemIndex());
    Thread::sleep(200); // otherwise load is called before the preset has actually been loaded
    loadZones();
    std::cout << "requested!" << std::endl;
  }else{
    AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
				     "Connection Error",
				     "BlipBox not connected!");
  }
}

#define NONE_SELECTED 0xff
uint8_t selected;
uint8_t PresetComponent::getSelectedZoneIndex(){
  return selected+1;
}
ScopedPointer<Animator> spanimator;
void PresetComponent::selectZone(uint8_t index){
  std::cout << "select zone " << (int)index << std::endl;
  if(index > 0 && index <= MAX_ZONES_IN_PRESET){
    selected = index-1;
    spanimator = new ZoneAreaAnimator(*preset->getZone(selected));
    ApplicationConfiguration::getBlipSim()->setAnimator(spanimator);
  }else{
    selected = NONE_SELECTED;
    spanimator = NULL;
    ApplicationConfiguration::getBlipSim()->setAnimator(preset);
    ApplicationConfiguration::getBlipSim()->setEventHandler(preset);
  }
  ApplicationConfiguration::getBlipSim()->doMidi(index == 0);
}

void PresetComponent::savePreset(uint8_t index){
  std::cout << "save preset " << (int)index << std::endl;
  preset->save(index);
}

void PresetComponent::loadPreset(uint8_t index){
  std::cout << "load preset " << (int)index << std::endl;

//   presetComboBox->setSelectedItemIndex(index, false);

  ApplicationConfiguration::getBlipSim()->setPresetIndex(index);
  preset->load(index);

  loadZones();
}

void PresetComponent::loadZones(){
  for(int i=0; i<components.size(); ++i)
    components[i]->loadZone(preset->getZone(i));
  selectZone(getSelectedZoneIndex());
}

void PresetComponent::saveFile(){
  File dir = ApplicationConfiguration::getPresetDirectory();
  if(!dir.exists())
    dir.createDirectory();
  FileChooser fc("Choose a file to save to...", dir,
		 "*.xml", useNativeVersion);
  if(fc.browseForFileToSave(true)){
    File file = fc.getResult();
    if(!file.hasFileExtension(".xml"))
      file = file.withFileExtension(".xml");
    // todo
//     preset->saveFile(file);
  }
}

void PresetComponent::loadFile(){
  FileChooser fc("Choose a file to open...",
		 ApplicationConfiguration::getPresetDirectory(),
// 		 File::getCurrentWorkingDirectory(),
		 "*.xml",
		  useNativeVersion);
  // todo
//   if(fc.browseForFileToOpen())
//     preset->loadFile(fc.getResult());
  loadZones();
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
                 fixedSize="0" initialWidth="600" initialHeight="700">
  <BACKGROUND backgroundColour="ffffffff"/>
  <JUCERCOMP name="" id="60caeec735b4583b" memberName="zone8" virtualName=""
             explicitFocusOrder="0" pos="80 568 512 72" sourceFile="ZoneComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="2ba6878101e39e9d" memberName="zone7" virtualName=""
             explicitFocusOrder="0" pos="80 496 512 72" sourceFile="ZoneComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="f150a24e5fa97df6" memberName="zone6" virtualName=""
             explicitFocusOrder="0" pos="80 424 512 72" sourceFile="ZoneComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="1a795bfc2c6dfd1c" memberName="zone5" virtualName=""
             explicitFocusOrder="0" pos="80 352 512 72" sourceFile="ZoneComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="f1a4f72b4b947356" memberName="zone4" virtualName=""
             explicitFocusOrder="0" pos="80 280 512 72" sourceFile="ZoneComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="8a33541f14a036d" memberName="zone3" virtualName=""
             explicitFocusOrder="0" pos="80 208 512 72" sourceFile="ZoneComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="46ed8e8b4db3c778" memberName="zone2" virtualName=""
             explicitFocusOrder="0" pos="80 136 512 72" sourceFile="ZoneComponent.cpp"
             constructorParams=""/>
  <TEXTBUTTON name="send" id="13dae98d24a6df1f" memberName="sendButton" virtualName=""
              explicitFocusOrder="0" pos="392 648 80 24" buttonText="send"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="500d6335007480ac" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="344 8 54 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Preset" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="Preset" id="95a22405f5cfbfc2" memberName="presetComboBox"
            virtualName="" explicitFocusOrder="10" pos="400 8 150 24" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="request button" id="6d5630b830980a64" memberName="requestButton"
              virtualName="" explicitFocusOrder="0" pos="472 648 80 24" buttonText="request"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <JUCERCOMP name="" id="cc448d859441e3cf" memberName="zone1" virtualName=""
             explicitFocusOrder="0" pos="80 64 512 72" sourceFile="ZoneComponent.cpp"
             constructorParams=""/>
  <TOGGLEBUTTON name="new toggle button" id="162d6fc3ec28538e" memberName="toggleButton1"
                virtualName="" explicitFocusOrder="1" pos="48 72 32 24" buttonText="1"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="93cf0f4ff2bc2160" memberName="toggleButton2"
                virtualName="" explicitFocusOrder="2" pos="48 144 32 24" buttonText="2"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="8222b08484d4cd87" memberName="toggleButton3"
                virtualName="" explicitFocusOrder="3" pos="48 216 32 24" buttonText="3"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="68774f91cf9a5989" memberName="toggleButton4"
                virtualName="" explicitFocusOrder="4" pos="48 288 32 24" buttonText="4"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="6ac4129d00e3e05b" memberName="toggleButton5"
                virtualName="" explicitFocusOrder="5" pos="48 360 32 24" buttonText="5"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="24b75ea8e86ff196" memberName="toggleButton6"
                virtualName="" explicitFocusOrder="6" pos="48 432 32 24" buttonText="6"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="8a2e65dc8c6aa7b2" memberName="toggleButton7"
                virtualName="" explicitFocusOrder="7" pos="48 504 32 24" buttonText="7"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="71291038b4f91490" memberName="toggleButton8"
                virtualName="" explicitFocusOrder="8" pos="48 576 32 24" buttonText="8"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <TEXTBUTTON name="save button" id="5f20cba43de4f1e8" memberName="saveButton"
              virtualName="" explicitFocusOrder="0" pos="120 648 80 24" buttonText="save"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="load button" id="175730ddac9ace26" memberName="loadButton"
              virtualName="" explicitFocusOrder="0" pos="200 648 80 24" buttonText="load"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="reset" id="68dc470f3c2876e2" memberName="settingsButton"
              virtualName="" explicitFocusOrder="0" pos="296 648 80 24" buttonText="settings"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="fc0dad117bb79388" memberName="runButton"
                virtualName="" explicitFocusOrder="9" pos="48 648 64 24" buttonText="run"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
