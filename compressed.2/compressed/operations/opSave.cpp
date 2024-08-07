#include "opSave.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opSave::opSave(controller* pCont) :operation(pCont)
{}
opSave::~opSave()
{}
void opSave::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	ofstream GameProgress("GameProgress.txt");
	pGraph->Save(GameProgress);
	GameProgress.close();
	pGraph->setsaved(true);  /// yetketeb f kol el operations
}


