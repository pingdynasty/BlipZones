/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  13 Aug 2011 8:50:28am

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
#include "SimScreen.h"
//[/Headers]

#include "BlipSimComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
BlipSimComponent::BlipSimComponent ()
    : screen (0)
{
    addAndMakeVisible (screen = new SimScreen());
    screen->setName (L"Simulator Screen");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

BlipSimComponent::~BlipSimComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (screen);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void BlipSimComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font (L"Helvetica", 22.0000f, Font::plain));
    g.drawText (L"blipbox",
                0, getHeight() - 30, proportionOfWidth (1.0000f), 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void BlipSimComponent::resized()
{
    screen->setBounds (0, 0, proportionOfWidth (1.0000f), getHeight() - 30);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void BlipSimComponent::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
  std::cout << "BlipSimComponent::mouseDrag" << std::endl;
    //[/UserCode_mouseDrag]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="BlipSimComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="0 30R 100% 30" fill="solid: ff000000" hasStroke="0" text="blipbox"
          fontname="Helvetica" fontsize="22" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="Simulator Screen" id="6ad56233c11e8a2" memberName="screen"
                    virtualName="SimScreen" explicitFocusOrder="0" pos="0 0 100% 30M"
                    class="" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
