/*
  ==============================================================================

    Simple desktop window.

  ==============================================================================
*/

#include "MainWindow.h"
// #include "ApplicationConfiguration.h"
#include "ConfigurationComponent.h"

//==============================================================================
MainAppWindow::MainAppWindow()
    : DocumentWindow (JUCEApplication::getInstance()->getApplicationName(),
                      Colours::lightgrey,
                      DocumentWindow::allButtons, true)
{
    centreWithSize (400, 700);
    setVisible (true);
    setResizable(true, true); // resizable, with resize corner (instead of border)

//     // todo: sort out preset choices
//     Preset* p = ApplicationConfiguration::getPreset(0);
//     preset = new PresetComponent(p);
//     setContentOwned(preset, true);
    component = new ConfigurationComponent();
    setContentOwned(component, true);
}

MainAppWindow::~MainAppWindow()
{
}

void MainAppWindow::closeButtonPressed()
{
//   delete this;
    JUCEApplication::getInstance()->systemRequestedQuit();
}
