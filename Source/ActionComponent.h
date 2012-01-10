/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  9 Dec 2011 1:40:10pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_ACTIONCOMPONENT_ACTIONCOMPONENT_EE41EA79__
#define __JUCER_HEADER_ACTIONCOMPONENT_ACTIONCOMPONENT_EE41EA79__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Action.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ActionComponent  : public Component
{
public:
    //==============================================================================
    ActionComponent ();
    ~ActionComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    virtual Action* getAction(){ return NULL; }
    virtual void loadAction(Action* action){ }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.

protected:
  bool dontSendChangeMessage;
  bool sendUpdateMessage;
  bool sendMessageSynchronously;
  bool allowNudgingOfOtherValues;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ActionComponent (const ActionComponent&);
    const ActionComponent& operator= (const ActionComponent&);
};


#endif   // __JUCER_HEADER_ACTIONCOMPONENT_ACTIONCOMPONENT_EE41EA79__
