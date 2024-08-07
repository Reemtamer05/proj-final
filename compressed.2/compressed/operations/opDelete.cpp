#include "opDelete.h"

#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opDelete::opDelete(controller* pCont) :operation(pCont)
{}
opDelete::~opDelete()
{}

//Execute the operation
void opDelete::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	//pGraph->Delete();
	if (pGraph->getselectedshape()) {
		pGraph->Delete();
		string msg = "selected shape is deleted";
		pUI->PrintMessage(msg);
	}
	else {
		string msg = "no selected shape.";
		pUI->PrintMessage(msg);
	}

}
