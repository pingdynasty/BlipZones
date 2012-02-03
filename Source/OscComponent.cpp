/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  3 Feb 2012 3:50:25am

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
    : maxSlider (0),
      minSlider (0),
      label (0),
      label2 (0),
      label3 (0),
      prefixEditor (0)
{
    addAndMakeVisible (maxSlider = new Slider (L"max"));
    maxSlider->setRange (0, 1, 0.1);
    maxSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    maxSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    maxSlider->addListener (this);

    addAndMakeVisible (minSlider = new Slider (L"min"));
    minSlider->setRange (0, 1, 0.1);
    minSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    minSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    minSlider->addListener (this);

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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 100);


    //[Constructor] You can add your own custom stuff here..
    prefixEditor->addListener (this);
    //[/Constructor]
}

OscComponent::~OscComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (maxSlider);
    deleteAndZero (minSlider);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (label3);
    deleteAndZero (prefixEditor);


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
    maxSlider->setBounds (448, 40, 64, 24);
    minSlider->setBounds (360, 40, 64, 24);
    label->setBounds (328, 40, 31, 24);
    label2->setBounds (416, 40, 32, 24);
    label3->setBounds (328, 8, 48, 24);
    prefixEditor->setBounds (376, 8, 128, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OscComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == maxSlider)
    {
        //[UserSliderCode_maxSlider] -- add your slider handling code here..
      action->maximum = maxSlider->getValue();
        //[/UserSliderCode_maxSlider]
    }
    else if (sliderThatWasMoved == minSlider)
    {
        //[UserSliderCode_minSlider] -- add your slider handling code here..
      action->minimum = minSlider->getValue();
        //[/UserSliderCode_minSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void OscComponent::loadAction(Action* anaction){
  action = dynamic_cast<OscAction*>(anaction);
  if(action != NULL){
    minSlider->setValue(action->minimum, sendUpdateMessage, sendMessageSynchronously);
    maxSlider->setValue(action->maximum, sendUpdateMessage, sendMessageSynchronously);
    prefixEditor->setText(action->prefix);
  }else{
    std::cout << "null action, dynamic cast failed " << anaction << std::endl;
  }
}

void OscComponent::textEditorTextChanged(TextEditor &editor){
  if(&editor == prefixEditor){
    action->prefix = prefixEditor->getText();
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
  <SLIDER name="max" id="aa57fa59b0b89fff" memberName="maxSlider" virtualName=""
          explicitFocusOrder="0" pos="448 40 64 24" min="0" max="1" int="0.1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="min" id="b0ac6409986e9469" memberName="minSlider" virtualName=""
          explicitFocusOrder="0" pos="360 40 64 24" min="0" max="1" int="0.1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="6bf549a531a0e0e9" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="328 40 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="min" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="389586e97e49a327" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="416 40 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="max" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5b78e24b9826b219" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="328 8 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="prefix" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="4e866dc7c74d9d80" memberName="prefixEditor"
              virtualName="" explicitFocusOrder="0" pos="376 8 128 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
