/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  10 Feb 2012 8:07:04pm

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

#include "OscComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OscComponent::OscComponent ()
    : label (0),
      label2 (0),
      label3 (0),
      prefixEditor (0),
      minEditor (0),
      maxEditor (0)
{
    addAndMakeVisible (label = new Label (L"new label",
                                          L"min"));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (L"new label",
                                           L"max"));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label3 = new Label (L"new label",
                                           L"prefix"));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (prefixEditor = new TextEditor (L"new text editor"));
    prefixEditor->setMultiLine (false);
    prefixEditor->setReturnKeyStartsNewLine (false);
    prefixEditor->setReadOnly (false);
    prefixEditor->setScrollbarsShown (true);
    prefixEditor->setCaretVisible (true);
    prefixEditor->setPopupMenuEnabled (true);
    prefixEditor->setText (String::empty);

    addAndMakeVisible (minEditor = new TextEditor (L"new text editor"));
    minEditor->setMultiLine (false);
    minEditor->setReturnKeyStartsNewLine (false);
    minEditor->setReadOnly (false);
    minEditor->setScrollbarsShown (true);
    minEditor->setCaretVisible (true);
    minEditor->setPopupMenuEnabled (true);
    minEditor->setText (L"0");

    addAndMakeVisible (maxEditor = new TextEditor (L"new text editor"));
    maxEditor->setMultiLine (false);
    maxEditor->setReturnKeyStartsNewLine (false);
    maxEditor->setReadOnly (false);
    maxEditor->setScrollbarsShown (true);
    maxEditor->setCaretVisible (true);
    maxEditor->setPopupMenuEnabled (true);
    maxEditor->setText (L"1.0");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 100);


    //[Constructor] You can add your own custom stuff here..
    prefixEditor->addListener (this);
    minEditor->addListener (this);
    maxEditor->addListener (this);
    minEditor->setInputRestrictions(14, "0123456789.-");
    maxEditor->setInputRestrictions(14, "0123456789.-");
    //[/Constructor]
}

OscComponent::~OscComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (label3);
    deleteAndZero (prefixEditor);
    deleteAndZero (minEditor);
    deleteAndZero (maxEditor);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OscComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xf5f9ea0));
    g.fillRoundedRectangle (0.0f, 0.0f, 510.0f, 68.0f, 3.5000f);

    g.setColour (Colours::cadetblue);
    g.drawRoundedRectangle (0.0f, 0.0f, 510.0f, 68.0f, 3.5000f, 0.5000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OscComponent::resized()
{
    label->setBounds (328, 40, 31, 24);
    label2->setBounds (424, 40, 32, 24);
    label3->setBounds (328, 8, 40, 24);
    prefixEditor->setBounds (368, 8, 136, 24);
    minEditor->setBounds (368, 40, 48, 24);
    maxEditor->setBounds (456, 40, 48, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void OscComponent::loadAction(Action* anaction){
  action = dynamic_cast<OscAction*>(anaction);
  if(action != NULL){
    minEditor->setText(String(action->minimum));
    maxEditor->setText(String(action->maximum));
    prefixEditor->setText(action->prefix);
  }else{
    std::cout << "null action, dynamic cast failed " << anaction << std::endl;
  }
}

void OscComponent::textEditorTextChanged(TextEditor &editor){
  if(&editor == prefixEditor){
    action->prefix = prefixEditor->getText();
  }else if(&editor == minEditor){
    action->minimum = minEditor->getText().getFloatValue();
  }else if(&editor == maxEditor){
    action->maximum = maxEditor->getText().getFloatValue();
  }
}
// void OscComponent::textEditorReturnKeyPressed (TextEditor &editor){}
// void OscComponent::textEditorEscapeKeyPressed (TextEditor &editor){}
// void OscComponent::textEditorFocusLost (TextEditor &editor){}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OscComponent" componentName=""
                 parentClasses="public ActionComponent, public TextEditor::Listener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330000013" fixedSize="0" initialWidth="600"
                 initialHeight="100">
  <BACKGROUND backgroundColour="ffffffff">
    <ROUNDRECT pos="0 0 510 68" cornerSize="3.5" fill="solid: f5f9ea0" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff5f9ea0"/>
  </BACKGROUND>
  <LABEL name="new label" id="6bf549a531a0e0e9" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="328 40 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="min" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="389586e97e49a327" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="424 40 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="max" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5b78e24b9826b219" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="328 8 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="prefix" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="4e866dc7c74d9d80" memberName="prefixEditor"
              virtualName="" explicitFocusOrder="0" pos="368 8 136 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="d0548205a1d20222" memberName="minEditor"
              virtualName="" explicitFocusOrder="0" pos="368 40 48 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="a3297ea03e61e7b3" memberName="maxEditor"
              virtualName="" explicitFocusOrder="0" pos="456 40 48 24" initialText="1.0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
