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

#ifndef __JUCER_HEADER_OSCCOMPONENT_OSCCOMPONENT_5118B348__
#define __JUCER_HEADER_OSCCOMPONENT_OSCCOMPONENT_5118B348__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "ActionComponent.h"
#include "OscAction.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OscComponent  : public ActionComponent,
                      public TextEditor::Listener,
                      public SliderListener
{
public:
    //==============================================================================
    OscComponent ();
    ~OscComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    Action* getAction(){
      return action;
    }
    void loadAction(Action* action);
    virtual void textEditorTextChanged (TextEditor &editor);
    virtual void textEditorReturnKeyPressed (TextEditor &editor){}
    virtual void textEditorEscapeKeyPressed (TextEditor &editor){}
    virtual void textEditorFocusLost (TextEditor &editor){}
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    OscAction* action;
    //[/UserVariables]

    //==============================================================================
    Slider* maxSlider;
    Slider* minSlider;
    Label* label;
    Label* label2;
    Label* label3;
    TextEditor* prefixEditor;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    OscComponent (const OscComponent&);
    const OscComponent& operator= (const OscComponent&);
};


#endif   // __JUCER_HEADER_OSCCOMPONENT_OSCCOMPONENT_5118B348__
