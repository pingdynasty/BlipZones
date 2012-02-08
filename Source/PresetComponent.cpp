/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  3 Feb 2012 10:27:47am

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
#include "PresetFactory.h"
//[/Headers]

#include "PresetComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PresetComponent::PresetComponent (Preset* p)
    : preset(p),
      zoneTypeComboBox (0),
      addButton (0),
      zones (0)
{
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

    setSize (560, 200);


    //[Constructor] You can add your own custom stuff here..
    zoneTypeComboBox->setSelectedItemIndex(0, false);
    loadZones();
    //[/Constructor]
}

PresetComponent::~PresetComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (zoneTypeComboBox);
    deleteAndZero (addButton);
    deleteAndZero (zones);


    //[Destructor]. You can add your own custom destruction code here..
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
    zoneTypeComboBox->setBounds (16, getHeight() - 32, 136, 24);
    addButton->setBounds (168, getHeight() - 32, 150, 24);
    zones->setBounds (0, 0, 580, getHeight() - 44);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PresetComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == zoneTypeComboBox)
    {
        //[UserComboBoxCode_zoneTypeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_zoneTypeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void PresetComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == addButton)
    {
        //[UserButtonCode_addButton] -- add your button handler code here..
      addZone();
        //[/UserButtonCode_addButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void PresetComponent::loadZones(){
  zones->updateContent();
}

void PresetComponent::addZone(){
  Zone* zone = PresetFactory::createZone(zoneTypeComboBox->getText());
  preset->addZone(zone);
  zone->setDisplayType(LINE_DISPLAY_TYPE);
  zones->updateContent();
}

Preset* PresetComponent::getPreset(){
  return preset;
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
                 snapShown="1" overlayOpacity="0.330000013" fixedSize="0" initialWidth="560"
                 initialHeight="200">
  <BACKGROUND backgroundColour="ffffffff"/>
  <COMBOBOX name="Zone Type" id="c60683b64f639182" memberName="zoneTypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="16 32R 136 24" editable="0"
            layout="33" items="Horizontal Slider&#10;Vertical Slider&#10;Momentary Button&#10;Toggle Button"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="d2ac626a2f30f00f" memberName="addButton"
              virtualName="" explicitFocusOrder="0" pos="168 32R 150 24" buttonText="add zone"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <JUCERCOMP name="" id="b8c5bc328fdcae1f" memberName="zones" virtualName="ZoneListBox"
             explicitFocusOrder="0" pos="0 0 580 44M" sourceFile="ZoneListBox.cpp"
             constructorParams="preset"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
