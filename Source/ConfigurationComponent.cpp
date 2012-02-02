/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  2 Feb 2012 12:05:26pm

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
#include "ApplicationSettingsComponent.h"
#include "ZoneAreaAnimator.h"
#include "PresetFactory.h"
#include "BlipSim.h"
#include "BlipClient.h"
//[/Headers]

#include "ConfigurationComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
const bool useNativeVersion = false;
//[/MiscUserDefs]

//==============================================================================
ConfigurationComponent::ConfigurationComponent ()
    : sendButton (0),
      requestButton (0),
      saveButton (0),
      loadButton (0),
      settingsButton (0),
      runButton (0),
      component (0),
      label7 (0),
      presetComboBox (0)
{
    addAndMakeVisible (sendButton = new TextButton (L"send"));
    sendButton->setConnectedEdges (Button::ConnectedOnRight);
    sendButton->addListener (this);

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

    addAndMakeVisible (component = new PresetComponent (getDefaultPreset()));
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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 600);


    //[Constructor] You can add your own custom stuff here..
    presetComboBox->setSelectedItemIndex(0, false);
    //[/Constructor]
}

ConfigurationComponent::~ConfigurationComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (sendButton);
    deleteAndZero (requestButton);
    deleteAndZero (saveButton);
    deleteAndZero (loadButton);
    deleteAndZero (settingsButton);
    deleteAndZero (runButton);
    deleteAndZero (component);
    deleteAndZero (label7);
    deleteAndZero (presetComboBox);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ConfigurationComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ConfigurationComponent::resized()
{
    sendButton->setBounds (400, getHeight() - 36, 80, 24);
    requestButton->setBounds (480, getHeight() - 36, 80, 24);
    saveButton->setBounds (128, getHeight() - 36, 80, 24);
    loadButton->setBounds (208, getHeight() - 36, 80, 24);
    settingsButton->setBounds (304, getHeight() - 36, 80, 24);
    runButton->setBounds (56, getHeight() - 36, 64, 24);
    component->setBounds (40, 48, 560, getHeight() - 100);
    label7->setBounds (352, 8, 54, 24);
    presetComboBox->setBounds (408, 8, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ConfigurationComponent::buttonClicked (Button* buttonThatWasClicked)
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ConfigurationComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == presetComboBox)
    {
        //[UserComboBoxCode_presetComboBox] -- add your combo box handling code here..
      loadPreset(presetComboBox->getSelectedItemIndex());
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

// void MidiZonePreset::loadPreset(uint8_t index){
//   std::cout << "MidiZonePreset::loadPreset " << (int)index << std::endl;
//   const MessageManagerLock mmLock;
//   pchack->loadPreset(index);
// }


Preset* ConfigurationComponent::getDefaultPreset(){
  std::cout << "get default preset " << std::endl;
  return ApplicationConfiguration::getPreset(0);
}

Preset* ConfigurationComponent::getCurrentPreset(){
  int index = presetComboBox->getSelectedItemIndex();
  std::cout << "get current preset " << index << std::endl;
  if(index < 0 || index > 7)
    index = 0;
  return ApplicationConfiguration::getPreset(index);
//   return ApplicationConfiguration::getBlipClient()->getPreset();
}

void ConfigurationComponent::sendPreset(){
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

void ConfigurationComponent::openSettings(){
  std::cout << "opening settings" << std::endl;
  ApplicationSettingsComponent component;
  if(component.showModalDialog(this)){
    ApplicationConfiguration::getBlipClient()->initialise();
    std::cout << "settings done" << std::endl;
  }
}

void ConfigurationComponent::requestPreset(){
  std::cout << "request!" << std::endl;
  if(ApplicationConfiguration::getBlipClient()->isConnected()){
    ApplicationConfiguration::getBlipClient()->requestPreset(presetComboBox->getSelectedItemIndex());
    Thread::sleep(200); // otherwise load is called before the preset has actually been loaded
    // todo!
//     Preset* = ApplicationConfiguration::getBlipClient()->getPreset();
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
// uint8_t ConfigurationComponent::getSelectedZoneIndex(){
//   return selected+1;
// }
// ScopedPointer<Animator> spanimator;
// void ConfigurationComponent::selectZone(uint8_t index){
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

void ConfigurationComponent::savePreset(uint8_t index){
  std::cout << "save preset " << (int)index << std::endl;

  // todo
//   for(int i=0; i<components.size(); ++i)
//     preset->setZone(i, components[i]->getZone());
//   preset->save(index);

}

void ConfigurationComponent::loadPreset(uint8_t index){
  std::cout << "load preset " << (int)index << std::endl;
    // todo: preset is now passed into constructor
  Preset* preset = ApplicationConfiguration::getPreset(index);
  removeChildComponent(component);
  delete component;
  addAndMakeVisible(component = new PresetComponent(preset));
//   repaint();
  resized();

//   zones->setPreset(preset);
// //   presetComboBox->setSelectedItemIndex(index, false);
//   ApplicationConfiguration::getBlipSim()->setPresetIndex(index);
//   if(preset == NULL)
//     return;
//   preset->load(index);
//   loadPreset(preset);
}

void ConfigurationComponent::loadPreset(Preset* p){
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

void ConfigurationComponent::saveFile(){
  File dir = ApplicationConfiguration::getPresetDirectory();
  if(!dir.exists())
    dir.createDirectory();
  FileChooser fc("Choose a file to save to...", dir,
		 "*.xml", useNativeVersion);
  if(fc.browseForFileToSave(true)){
    Preset* preset = getCurrentPreset();
    File file = fc.getResult();
    if(!file.hasFileExtension(".xml"))
      file = file.withFileExtension(".xml");
    PresetFactory factory;
    factory.savePreset(*preset, file);
  }
}

void ConfigurationComponent::loadFile(){
  FileChooser fc("Choose a file to open...",
		 ApplicationConfiguration::getPresetDirectory(),
// 		 File::getCurrentWorkingDirectory(),
		 "*.xml",
		  useNativeVersion);
  PresetFactory factory;
  Preset* preset = getCurrentPreset();
  if(fc.browseForFileToOpen()){
    File file = fc.getResult();
    // todo!
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

<JUCER_COMPONENT documentType="Component" className="ConfigurationComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="600">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="send" id="13dae98d24a6df1f" memberName="sendButton" virtualName=""
              explicitFocusOrder="0" pos="400 36R 80 24" buttonText="send"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="request button" id="6d5630b830980a64" memberName="requestButton"
              virtualName="" explicitFocusOrder="0" pos="480 36R 80 24" buttonText="request"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="save button" id="5f20cba43de4f1e8" memberName="saveButton"
              virtualName="" explicitFocusOrder="0" pos="128 36R 80 24" buttonText="save"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="load button" id="175730ddac9ace26" memberName="loadButton"
              virtualName="" explicitFocusOrder="0" pos="208 36R 80 24" buttonText="load"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="reset" id="68dc470f3c2876e2" memberName="settingsButton"
              virtualName="" explicitFocusOrder="0" pos="304 36R 80 24" buttonText="settings"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="fc0dad117bb79388" memberName="runButton"
                virtualName="" explicitFocusOrder="9" pos="56 36R 64 24" buttonText="run"
                connectedEdges="0" needsCallback="1" radioGroupId="1005" state="0"/>
  <JUCERCOMP name="" id="5b591b1380507d69" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="40 48 560 100M" sourceFile="PresetComponent.cpp"
             constructorParams="getDefaultPreset()"/>
  <LABEL name="new label" id="500d6335007480ac" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="352 8 54 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Preset" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="Preset" id="95a22405f5cfbfc2" memberName="presetComboBox"
            virtualName="" explicitFocusOrder="10" pos="408 8 150 24" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
