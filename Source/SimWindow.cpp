#include "SimWindow.h"
#include "BlipSimComponent.h"
#include "ApplicationConfiguration.h"

SimWindow::SimWindow()
  : DocumentWindow (T("BlipSim"),
		    Colours::lightgrey,
		    DocumentWindow::allButtons, true)
{
    centreWithSize (400, 500);
    setVisible (true);
    setResizable(true, true); // resizable, with resize corner (instead of border)
    sim = new BlipSimComponent();
    setContentOwned(sim, true);
    ApplicationConfiguration::setSimScreen(sim->getSimScreen());
}

SimWindow::~SimWindow()
{
}

void SimWindow::closeButtonPressed()
{
//   delete this;
  JUCEApplication::getInstance()->systemRequestedQuit();
}

