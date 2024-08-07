#include "opExit.h"
#include <fstream>
#include "..\controller.h"

#include "..\GUI\GUI.h"

opExit::opExit(controller* pCont) : operation(pCont) {}
opExit:: ~opExit() {}


void opExit::Execute()
{
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	ofstream GameProgress("GameProgress.txt");
	/*pUI->Save(GameProgress);*/
	pGraph->Save(GameProgress);
	pGraph->Exit();
}
