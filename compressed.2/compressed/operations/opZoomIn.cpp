#include "opZoomIn.h"
#include <string>
#include "..\controller.h"
#include "..\Shapes\Graph.h"
#include "..\GUI\GUI.h"


// Constructor
opZoomIn::opZoomIn(controller* pCont) : operation(pCont) {}

// Destructor
opZoomIn::~opZoomIn() {}

// Execute the Zoom In operation
void opZoomIn::Execute() {
    // Retrieve the GUI interface pointer
    GUI* pUI = pControl->GetUI();

    // Prompt the user for a zoom in factor
    pUI->PrintMessage("Enter zoom in factor (e.g., 1.1 for 10% zoom in): ");
    std::string zoomStr = pUI->GetSrting();

    double zoomFactor = 1.0;
    try {
        // Convert the input string to a double representing the zoom factor
        zoomFactor = std::stod(zoomStr);
    }
    catch (...) {
        // If conversion fails, use a default zoom factor
        pUI->PrintMessage("Invalid input. Using default zoom factor of 1.1.");
        zoomFactor = 1.1;
    }

    // Retrieve the graph and apply the zoom factor
    Graph* pGr = pControl->getGraph();
    pGr->Zoom(zoomFactor);

    // Clear the status bar and notify the user that the operation is complete
    pUI->ClearStatusBar();
    pUI->PrintMessage("Zoom In executed.");
}