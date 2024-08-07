#include "controller.h"
#include "operations/opAddRect.h"
#include "operations\opSave.h"
#include "operations\opDelete.h"
//#include "operations/opAddStick.h"
#include "operations/opZoomIn.h"
#include "operations/opZoomOut.h"
#include "operations/opZoomOut.h"
#include "operations/opExit.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{	
		case DRAW_LINE:
			///create AddLineoperation here
			pOp = new opAddLINE(this);
			break;
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;
		case DRAW_TRI:
			pOp = new opAddTRI(this);
			break;
		case DRAW_CIRC:
			pOp = new opAddCRC(this);
			break;

	
		case DRAW_SQR:
			///create AddLineoperation here
			pOp = new opAddSQR(this);
			break;
		case DRAW_REGPOLY:
			///create AddLineoperation here
			pOp = new opAddRegPoly(this);
			break;

		case DRAW_OVAL:
			///create AddLineoperation here
			pOp = new opAddOval(this);
			break;

		case DRAW_STICK:
		case CHNG_DRAW_CLR:
		case CHNG_FILL_CLR:
		case CHNG_BK_CLR:

		case DEL:
			pOp = new opDelete(this);
		case SAVE:
			pOp = new opSave(this);
				break;

	
		case LOAD:
			pOp = new opaddload(this);
		case SELECT:
			pOp = new opselect(this);

		//case DRAW_STICK:
		//	pOp = new opAddStick(this, "images/MenuIcons/Menu_Java.jpg"); // Example path
		//	break;

		case ZOOM_IN:
			pOp = new opZoomIn(this); // Instantiate ZoomIn operation
			break;

		case ZOOM_OUT:
			pOp = new opZoomOut(this); // Instantiate ZoomOut operation
			break;

	

		case EXIT:
			pOp = new opExit(this);
			///create Exitoperation here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);
	/*operation* opSaved = new opSave(this);
	opSaved->Execute();*/

}