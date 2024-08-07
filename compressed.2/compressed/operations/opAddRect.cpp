#include "opAddRect.h"
#include "..\shapes\Rect.h"
#include "../Shapes/circle.h"
#include "../Shapes/line.h"
#include "../Shapes/square.h"
#include "../Shapes/RegPoly.h"
#include "../Shapes/triangle.h"
#include "../Shapes/Oval.h"



#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddRect::opAddRect(controller * pCont):operation(pCont)
{}
opAddRect::~opAddRect()
{} 

//Execute the operation
void opAddRect::Execute() 
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Rectangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;
	
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = false;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	Rect *R=new Rect(P1, P2, RectGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}

opAddCRC::opAddCRC(controller* pCont) :operation(pCont)
{
}

opAddCRC::~opAddCRC()
{
}

void opAddCRC::Execute()
{
	Point center;
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Circle: Click at the center");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(center.x, center.y);

	string msg = "Radius is at (" + to_string(center.x) + ", " + to_string(center.y) + " )";
	pUI->PrintMessage(msg);

	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo CircleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CircleGfxInfo.FillClr = pUI->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	CircleGfxInfo.isFilled = false;	//default is not filled
	CircleGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	circle* R = new circle(center, CircleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);
}


opAddLINE::opAddLINE(controller* pCont) : operation(pCont) {}

opAddLINE::~opAddLINE()
{
}

void opAddLINE::Execute()
{
	Point p3;
	Point p4;
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at first point");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(p3.x, p3.y);

	string msg = "First point is at (" + to_string(p3.x) + ", " + to_string(p3.y) + " )";
	msg += " ... Click at second point";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(p4.x, p4.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo LINEGfxInfo;

	//get drawing, filling colors and pen width from the interface
	LINEGfxInfo.DrawClr = pUI->getCrntDrawColor();
	LINEGfxInfo.FillClr = pUI->getCrntFillColor();
	LINEGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	LINEGfxInfo.isFilled = false;	//default is not filled
	LINEGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	Line* R = new Line(p3, p4, LINEGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}

opAddSQR::opAddSQR(controller* pCont) :operation(pCont)
{
}

opAddSQR::~opAddSQR()
{
}

void opAddSQR::Execute()
{
	Point s , p4;
	int slength;
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(s.x, s.y);

	string msg = "First corner is at (" + to_string(s.x) + ", " + to_string(s.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(p4.x, p4.y); 
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo SQRGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SQRGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SQRGfxInfo.FillClr = pUI->getCrntFillColor();
	SQRGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	SQRGfxInfo.isFilled = false;	//default is not filled
	SQRGfxInfo.isSelected = false;	//defualt is not selected
	slength = abs(s.x - p4.x);

	//Create a rectangle with the above parameters
	square* R = new square(s, slength, SQRGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);
}





opAddRegPoly::opAddRegPoly(controller* pCont) : operation(pCont) {}
opAddRegPoly::~opAddRegPoly() {}


void opAddRegPoly::Execute() {
	Point P1, P2;


	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Regular Polygon: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	pUI->SetPenWidth(8);
	GfxInfo RegPolyGfxInfo;
	//get drawing, filling colors and pen width from the interface
	RegPolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RegPolyGfxInfo.FillClr = pUI->getCrntFillColor();
	RegPolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	RegPolyGfxInfo.isFilled = false; // Set to true to fill the polygon
	RegPolyGfxInfo.isSelected = false; //default is not selected

	int vert_num = 12;

	//Create a regular polygon with the above parameters
	RegPoly* R = new RegPoly(P1, P2, vert_num, RegPolyGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the polygon to the list of shapes
	pGr->Addshape(R);
}

//
//opAddRegPoly::opAddRegPoly(controller* pCont) : operation(pCont) {}
//opAddRegPoly::~opAddRegPoly() {}
//
//
//void opAddRegPoly::Execute() {
//	Point P1, P2;
//
//
//	GUI* pUI = pControl->GetUI();
//
//	pUI->PrintMessage("New Regular Polygon: Click at first corner");
//	//Read 1st corner and store in point P1
//	pUI->GetPointClicked(P1.x, P1.y);
//
//	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
//	msg += " ... Click at second corner";
//	pUI->PrintMessage(msg);
//	//Read 2nd corner and store in point P2
//	pUI->GetPointClicked(P2.x, P2.y);
//	pUI->ClearStatusBar();
//
//
//	GfxInfo RegPolyGfxInfo;
//	//get drawing, filling colors and pen width from the interface
//	RegPolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
//	RegPolyGfxInfo.FillClr = pUI->getCrntFillColor();
//	RegPolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();
//
//	RegPolyGfxInfo.isFilled = true; // Set to true to fill the polygon
//	RegPolyGfxInfo.isSelected = false; //default is not selected
//
//	int vert_num = 10;
//
//	//Create a regular polygon with the above parameters
//	RegPoly* R = new RegPoly(P1, P2, vert_num, RegPolyGfxInfo);
//
//	//Get a pointer to the graph
//	Graph* pGr = pControl->getGraph();
//
//	//Add the polygon to the list of shapes
//	pGr->Addshape(R);
//
//}


opAddTRI::opAddTRI(controller* pCont) :operation(pCont)
{
}

opAddTRI::~opAddTRI()
{
}

void opAddTRI::Execute()
{
	Point vertix1, vertix2, vertix3;
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(vertix1.x, vertix1.y);

	string msg = "First corner is at (" + to_string(vertix1.x) + ", " + to_string(vertix1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(vertix2.x, vertix2.y);
	//3rd corner
	pUI->GetPointClicked(vertix3.x, vertix3.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo TRIGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TRIGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TRIGfxInfo.FillClr = pUI->getCrntFillColor();
	TRIGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	TRIGfxInfo.isFilled = false;	//default is not filled
	TRIGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	triangle* R = new triangle(vertix1, vertix2, vertix3, TRIGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);
}


opAddOval::opAddOval(controller* pCont) : operation(pCont) {}

opAddOval::~opAddOval() {}

// Execute the operation
void opAddOval::Execute() {
	// Existing code for adding an Oval...
	Point P1, P2;

	// Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Oval: Click at first corner");
	// Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + std::to_string(P1.x) + ", " + std::to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	// Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	// Prepare all Oval parameters
	GfxInfo OvalGfxInfo;

	// Get drawing, filling colors, and pen width from the interface
	OvalGfxInfo.DrawClr = pUI->getCrntDrawColor();
	OvalGfxInfo.FillClr = pUI->getCrntFillColor();
	OvalGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	OvalGfxInfo.isFilled = true;   // Default is not filled
	OvalGfxInfo.isSelected = true; // Default is not selected

	// Create an Oval with the above parameters
	Oval* R = new Oval(P1, P2, OvalGfxInfo);

	// Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	// Add the Oval to the list of shapes
	pGr->Addshape(R);


}


opChangeFillColor::opChangeFillColor(controller* pCont) :operation(pCont)
{}
opChangeFillColor::~opChangeFillColor()
{}

void opChangeFillColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	/*pUI->CreateColorPalette();*/
	// Display the color palette

	int x, y;
	pUI->GetPointClicked(x, y);
	// Get user click



	// Apply the new fill color to selected shapes
	Graph* pGraph = pControl->getGraph();
	// Loop through shapes and update the fill color
}


opChangeDrawColor::opChangeDrawColor(controller* pCont) :operation(pCont)
{}
opChangeDrawColor::~opChangeDrawColor()
{}

void opChangeDrawColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	//pUI->CreateColorPalette();
	// by3ml display ll color palette

	int x, y;
	pUI->GetPointClicked(x, y);



	// Apply the new fill color to selected shapes
	Graph* pGraph = pControl->getGraph();
	// Loop through shapes and update the fill color
}



void opchangebr::Execute()
{
	GUI* PG = pControl->GetUI();
	Graph* phraph = pControl->getGraph();
	color c = phraph->getcolor();

	PG->setcolor(c);
}


opselect::opselect(controller* pCont) :operation(pCont)
{}
opselect::~opselect()
{}
void opselect::Execute()
{
	Point p;
	GUI* PG = pControl->GetUI();

	PG->GetPointClicked(p.x, p.y);
	Graph* pgr = pControl->getGraph();
	pgr->Getshape(p.x, p.y);
	shape* psh;
	// psh-> //
	if (psh != NULL) {
		psh->SetSelected(!psh->IsSelected());
	}
}

opaddload::opaddload(controller* pCont) :operation(pCont)
{
}

opaddload::~opaddload()
{
}

void opaddload::Execute()
{
	ifstream infile;
	GUI* PG = pControl->GetUI();
	Graph* gph;
	gph->load(infile);
}
opResize::opResize(controller* pCont) :operation(pCont)
{
}

opResize::~opResize()
{
}

void opResize::Execute()
{
	GUI* pGUI;
	shape* selectedShape;
	pGUI->PrintMessage("Enter resize factor (0.25, 0.5, 2, 4): ");
	double size = std::stod(pGUI->GetSrting());
	selectedShape->Resize(size);
	pGUI->PrintMessage("Shape resized.");

}

