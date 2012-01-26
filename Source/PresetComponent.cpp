/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  23 Jan 2012 2:56:11pm

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
#include "PresetFactory.h"
#include "BlipSim.h"
#include "BlipClient.h"
//[/Headers]

#include "PresetComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
const bool useNativeVersion = false;

//[/MiscUserDefs]

//==============================================================================
PresetComponent::PresetComponent (Preset* p)
    : preset(p),
      sendButton (0),
      label7 (0),
      presetComboBox (0),
      requestButton (0),
      saveButton (0),
      loadButton (0),
      settingsButton (0),
      runButton (0),
      zoneTypeComboBox (0),
      addButton (0),
      zones (0)
{
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

    addAndMakeVisible (zoneTypeComboBox = new ComboBox (L"Zone Type"));
    zoneTypeComboBox->setEditableText (false);
    zoneTypeComboBox->setJustificationType (Justification::centredLeft);
    zoneTypeComboBox->setTextWhenNothingSelected (String::empty);
    zoneTypeComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    zoneTypeComboBox->addItem (L"Horizontal Slider", 1);
    zoneTypeComboBox->addItem (L"Vertical Slider", 2);
    zoneTypeComboBox->addItem (L"Momentary Button", 3);
    zoneTypeComboBox->addItem (L"Toggle Button", 4);
    zoneTypeComboBox->addListener (this);

    addAndMakeVisible (addButton = new TextButton (L"new button"));
    addButton->setButtonText (L"add zone");
    addButton->addListener (this);

    addAndMakeVisible (zones = new ZoneListBox (preset));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 700);


    //[Constructor] You can add your own custom stuff here..
    // todo: preset is now passed into constructor
//     preset = new Preset();
//     preset = ApplicationConfiguration::getPreset(0);
//     presetComboBox->setSelectedItemIndex(0, false);
//     loadPreset(presetComboBox->getSelectedItemIndex());
    //[/Constructor]
}

PresetComponent::~PresetComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (sendButton);
    deleteAndZero (label7);
    deleteAndZero (presetComboBox);
    deleteAndZero (requestButton);
    deleteAndZero (saveButton);
    deleteAndZero (loadButton);
    deleteAndZero (settingsButton);
    deleteAndZero (runButton);
    deleteAndZero (zoneTypeComboBox);
    deleteAndZero (addButton);
    deleteAndZero (zones);


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
    sendButton->setBounds (392, 648, 80, 24);
    label7->setBounds (344, 8, 54, 24);
    presetComboBox->setBounds (400, 8, 150, 24);
    requestButton->setBounds (472, 648, 80, 24);
    saveButton->setBounds (120, 648, 80, 24);
    loadButton->setBounds (200, 648, 80, 24);
    settingsButton->setBounds (296, 648, 80, 24);
    runButton->setBounds (48, 648, 64, 24);
    zoneTypeComboBox->setBounds (48, 592, 136, 24);
    addButton->setBounds (200, 592, 150, 24);
    zones->setBounds (48, 152, 544, 392);
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
      // todo!
//       selectZone(0);
        //[/UserButtonCode_runButton]
    }
    else if (buttonThatWasClicked == addButton)
    {
        //[UserButtonCode_addButton] -- add your button handler code here..
      addZone();
        //[/UserButtonCode_addButton]
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
    // todo: preset is now passed into constructor
//       savePreset(ApplicationConfiguration::getBlipSim()->getPresetIndex());
//       loadPreset(comboBoxThatHasChanged->getSelectedItemIndex());
        //[/UserComboBoxCode_presetComboBox]
    }
    else if (comboBoxThatHasChanged == zoneTypeComboBox)
    {
        //[UserComboBoxCode_zoneTypeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_zoneTypeComboBox]
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

// void MidiZonePreset::loadPreset(uint8_t index){
//   std::cout << "MidiZonePreset::loadPreset " << (int)index << std::endl;
//   const MessageManagerLock mmLock;
//   pchack->loadPreset(index);
// }

void PresetComponent::addZone(){
  uint8_t index = preset->getNumberOfZones();
  std::cout << "add zone " << (int)index << std::endl;
  Zone* zone = NULL;
  switch(zoneTypeComboBox->getSelectedId()){
  case 1:
    zone = Zone::createZone(HORIZONTAL_SLIDER_ZONE_TYPE);
    break;
  case 2:
    zone = Zone::createZone(VERTICAL_SLIDER_ZONE_TYPE);
    break;
  case 3:
    zone = Zone::createZone(MOMENTARY_BUTTON_ZONE_TYPE);
    break;
  case 4:
    zone = Zone::createZone(TOGGLE_BUTTON_ZONE_TYPE);
    break;
//   case 5:
//   default:
  }
//   zone->action = NULL; // todo: why is the constructor not called?
  preset->setZone(index, zone);
  zones->updateContent();
//   zones->repaint();
//   repaint();
}

void PresetComponent::release(){
}

Preset* PresetComponent::getPreset(){
  return preset;
}

void PresetComponent::sendPreset(){
  std::cout << "send!" << std::endl;
  if(ApplicationConfiguration::getBlipClient()->isConnected()){
//     ApplicationConfiguration::getBlipClient()->sendPreset(presetComboBox->getSelectedItemIndex());
    // todo!
//     ApplicationConfiguration::getBlipClient()->sendPreset(preset);
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
  if(component.showModalDialog(this)){
    ApplicationConfiguration::getBlipClient()->initialise();
    std::cout << "settings done" << std::endl;
  }
}

void PresetComponent::requestPreset(){
  std::cout << "request!" << std::endl;
  if(ApplicationConfiguration::getBlipClient()->isConnected()){
    ApplicationConfiguration::getBlipClient()->requestPreset(presetComboBox->getSelectedItemIndex());
    Thread::sleep(200); // otherwise load is called before the preset has actually been loaded
    // todo!
//     loadPreset(BlipClient.getPreset());
//     loadPreset(preset);
    std::cout << "requested!" << std::endl;
  }else{
    AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
				     "Connection Error",
				     "BlipBox not connected!");
  }
}

// #define NONE_SELECTED 0xff
// uint8_t selected;
// uint8_t PresetComponent::getSelectedZoneIndex(){
//   return selected+1;
// }
// ScopedPointer<Animator> spanimator;
// void PresetComponent::selectZone(uint8_t index){
//   std::cout << "select zone " << (int)index << std::endl;
//   if(index > 0 && index <= MAX_ZONES_IN_PRESET){
//     selected = index-1;
//     if(preset->getZone(selected) != NULL){
//       spanimator = new ZoneAreaAnimator(*preset->getZone(selected));
//       ApplicationConfiguration::getBlipSim()->setAnimator(spanimator);
//     }
//   }else{
//     selected = NONE_SELECTED;
//     spanimator = NULL;
//     ApplicationConfiguration::getBlipSim()->setAnimator(preset);
//     ApplicationConfiguration::getBlipSim()->setEventHandler(preset);
//   }
//   ApplicationConfiguration::getBlipSim()->doMidi(index == 0);
// }

void PresetComponent::savePreset(uint8_t index){
  std::cout << "save preset " << (int)index << std::endl;

  // todo
//   for(int i=0; i<components.size(); ++i)
//     preset->setZone(i, components[i]->getZone());
//   preset->save(index);

}

void PresetComponent::loadPreset(uint8_t index){
  std::cout << "load preset " << (int)index << std::endl;
    // todo: preset is now passed into constructor
//   preset = ApplicationConfiguration::getPreset(index);
//   zones->setPreset(preset);
// //   presetComboBox->setSelectedItemIndex(index, false);
//   ApplicationConfiguration::getBlipSim()->setPresetIndex(index);
//   if(preset == NULL)
//     return;
//   preset->load(index);
//   loadPreset(preset);
}

void PresetComponent::loadPreset(Preset* p){
//   preset = p;

  // todo
//   for(int i=0; i<components.size(); ++i){
// //   components.clear();
// //   for(int i=0; i<MAX_ZONES_IN_PRESET; ++i){
//     Zone* zone = preset->getZone(i);
// //     deleteAndZero(components[i]);
// //     if(zone == NULL){
// //     components.add(new ZoneComponent());
//     components[i]->loadZone(zone);
//   }
//   selectZone(getSelectedZoneIndex());
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
    PresetFactory factory;
    factory.savePreset(*preset, file);
  }
}

void PresetComponent::loadFile(){
  FileChooser fc("Choose a file to open...",
		 ApplicationConfiguration::getPresetDirectory(),
// 		 File::getCurrentWorkingDirectory(),
		 "*.xml",
		  useNativeVersion);
  PresetFactory factory;
  if(fc.browseForFileToOpen()){
    File file = fc.getResult();
    factory.loadPreset(*preset, file);
  }
  loadPreset(preset);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PresetComponent" componentName=""
                 parentClasses="public Component" constructorParams="Preset* p"
                 variableInitialisers="preset(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330000013" fixedSize="0" initialWidth="600"
                 initialHeight="700">
  <BACKGROUND backgroundColour="ffffffff"/>
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
  <COMBOBOX name="Zone Type" id="c60683b64f639182" memberName="zoneTypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="48 592 136 24" editable="0"
            layout="33" items="Horizontal Slider&#10;Vertical Slider&#10;Momentary Button&#10;Toggle Button"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="d2ac626a2f30f00f" memberName="addButton"
              virtualName="" explicitFocusOrder="0" pos="200 592 150 24" buttonText="add zone"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <JUCERCOMP name="" id="b8c5bc328fdcae1f" memberName="zones" virtualName=""
             explicitFocusOrder="0" pos="48 152 544 392" sourceFile="ZoneListBox.cpp"
             constructorParams="preset"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
