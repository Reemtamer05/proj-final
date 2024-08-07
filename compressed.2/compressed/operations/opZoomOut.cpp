#include "opZoomOut.h"
#include <string>
#include "..\controller.h"
#include "..\Shapes\Graph.h"
#include "..\GUI\GUI.h"



// Constructor
opZoomOut::opZoomOut(controller* pCont) : operation(pCont) {}

// Destructor
opZoomOut::~opZoomOut() {}

void opZoomOut::Execute() {
    // Retrieve the GUI interface pointer
    GUI* pUI = pControl->GetUI();

    // Prompt the user for a zoom out factor & Fix the hard coding in phase 1 
    pUI->PrintMessage("Enter zoom out factor (0.9 for 10% zoom out): ");
    std::string zoomStr = pUI->GetSrting();

    double zoomFactor = 1.0;
    try {
        // Convert the input string to a double representing the zoom factor
        zoomFactor = std::stod(zoomStr);
    }
    catch (...) {
        // If conversion fails, use a default zoom factor
        pUI->PrintMessage("Invalid input. Using default zoom factor of 0.9.");
        zoomFactor = 0.9;
    }

    // Retrieve the graph and apply the zoom factor
    Graph* pGr = pControl->getGraph();
    pGr->Zoom(zoomFactor);

    // Clear the status bar and notify the user that the operation is complete
    pUI->ClearStatusBar();
    pUI->PrintMessage("Zoom Out executed.");
}

