#include "SimWindow.h"
#include "BlipSimComponent.h"

SimWindow::SimWindow()
  : DocumentWindow (T("BlipSim"),
		    Colours::lightgrey,
		    DocumentWindow::allButtons, true)
{
    centreWithSize (500, 400);
    setVisible (true);
    setResizable(true, true); // resizable, with resize corner (instead of border)
    sim = new BlipSimComponent();
    setContentOwned(sim, true);
}

SimWindow::~SimWindow()
{
  deleteAndZero(sim);
}

void SimWindow::closeButtonPressed()
{
//     JUCEApplication::getInstance()->systemRequestedQuit();
}

