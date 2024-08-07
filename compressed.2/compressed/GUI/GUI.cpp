#include "GUI.h"

GUI::GUI()
{

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 46;

	DrawColor = DARKGREEN;	//default Drawing color
	FillColor = YELLOW;	//default Filling color
	MsgColor = BLUE;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use it for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	//[1] If user clicks on the Toolbar
	if (y >= 0 && y < ToolBarHeight)
	{
		//Check whick Menu icon was clicked
		//==> This assumes that menu icons are lined up horizontally <==
		int ClickedIconOrder = (x / MenuIconWidth);
		//Divide x coord of the point clicked by the menu icon width (int division)
		//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

		switch (ClickedIconOrder)
		{
		case ICON_RECT: return DRAW_RECT;
		case ICON_CIRCLE: return DRAW_CIRC;
		case ICON_TRI: return DRAW_TRI;
		case ICON_LINE: return DRAW_LINE;
		case ICON_SQR: return DRAW_SQR;
		case ICON_REGPOLY: return DRAW_REGPOLY;
		case ICON_OVAL: return DRAW_OVAL;
		case ICON_STICK: return DRAW_STICK;
		case ICON_FILL: return CHNG_FILL_CLR;
		case ICON_PEN: return CHNG_DRAW_CLR;
		case ICON_SAVE: return SAVE;
		case ICON_LOAD: return LOAD;
		case ICON_DEL: return DEL;
		case ICON_RES: return RESIZE;
		case ICON_MOVE: return MOVE;
		case ICON_ROT: return ROTATE;
		case ICON_SEND: return SEND_BACK;
		case ICON_BRING: return BRNG_FRNT;
		case ICON_DRAW: return TO_DRAW;
		case ICON_PLAY: return TO_PLAY;
		case ICON_SELECT: return SELECT;
		case ICON_COPY: return COPY;
		case ICON_PASTE: return PASTE;
		case ICON_CUT: return CUT;
		case ICON_ZOMIN: return ZOOM_IN;
		case ICON_ZOMOUT: return ZOOM_OUT;
		case ICON_EXIT: return EXIT;

		default: return EMPTY;	//A click on empty place in desgin toolbar
		}
	}

	//[2] User clicks on the drawing area
	if (y >= ToolBarHeight && y < height - StatusBarHeight)
	{
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;
	

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_Tri.jpg";
	MenuIconImages[ICON_CIRCLE] = "images\\MenuIcons\\Menu_Circle.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_SQR] = "images\\MenuIcons\\Menu_Sqr.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\Menu_Oval.jpg";
	MenuIconImages[ICON_REGPOLY] = "images\\MenuIcons\\Menu_Regpoly.jpg";
	MenuIconImages[ICON_STICK] = "images\\MenuIcons\\Menu_Stick.jpg";
	MenuIconImages[ICON_FILL] = "images\\MenuIcons\\Menu_Fill.jpg";
	MenuIconImages[ICON_PEN] = "images\\MenuIcons\\Menu_Pen.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_DEL] = "images\\MenuIcons\\Menu_Del.jpg";
	MenuIconImages[ICON_RES] = "images\\MenuIcons\\Menu_Res.jpg";
	MenuIconImages[ICON_MOVE] = "images\\MenuIcons\\Menu_Move.jpg";
	MenuIconImages[ICON_ROT] = "images\\MenuIcons\\Menu_Rot.jpg";
	MenuIconImages[ICON_SEND] = "images\\MenuIcons\\Menu_Send.jpg";
	MenuIconImages[ICON_BRING] = "images\\MenuIcons\\Menu_Bring.jpg";
	MenuIconImages[ICON_DRAW] = "images\\MenuIcons\\Menu_Draw.jpg";
	MenuIconImages[ICON_PLAY] = "images\\MenuIcons\\Menu_Play.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\Menu_Select.jpg";
	MenuIconImages[ICON_COPY] = "images\\MenuIcons\\Menu_Copy.jpg";
	MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\Menu_Paste.jpg";
	MenuIconImages[ICON_CUT] = "images\\MenuIcons\\Menu_Cut.jpg";
	MenuIconImages[ICON_ZOMIN] = "images/MenuIcons/Menu_Zomin.jpg";
	MenuIconImages[ICON_ZOMOUT] = "images/MenuIcons/Menu_Zomout.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";


	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////



void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}



void GUI::SetPenWidth(int width) {
	PenWidth = width;
}


color GUI::getcolor()
{
	window* pW = new window(400, 400, 3, 3); //yeftah window b soret el palette akbar
	pW->DrawImage("images\\MenuIcons\\Menu_Palette.jpg", 0, 0, 400, 400);
	int x; int y; //dimensions makan ma 3amal click
	pW->WaitMouseClick(x, y);
	color c = pW->GetColor(x, y); //akhad el color makan ma 3amal click
	delete pW; //ye2fel el window
	return c; //yeraga3 el color f variable yekon mahtoot feh
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::Drawcircle(Point center, int radius, GfxInfo CircleGfxInfo) const
{
	color DrawingClr;
	if (CircleGfxInfo.isSelected)  // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);  // Set Drawing color & width

	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(center.x, center.y, radius, style);
}



void GUI::DrawTRI(Point vertix1, Point vertix2, Point vertix3, GfxInfo TRIGfxInfo) const
{
	color DrawingClr;
	if (TRIGfxInfo.isSelected)  // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = TRIGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TRIGfxInfo.BorderWdth);  // Set Drawing color & width

	drawstyle style;
	if (TRIGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TRIGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(vertix1.x, vertix1.y, vertix2.x, vertix2.y, vertix3.x, vertix3.y, style);
}

void GUI::DrawSQR(Point s, int slength, GfxInfo SQRGfxInfo) const
{
	color DrawingClr;
	if (SQRGfxInfo.isSelected)  // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = SQRGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SQRGfxInfo.BorderWdth);  // Set Drawing color & width

	drawstyle style;
	if (SQRGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SQRGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(s.x, s.y, s.x + slength, s.y + slength, style);
}



void GUI::DrawLINE(Point p3, Point p4, GfxInfo LINEGfxInfo) const
{
	color DrawingClr;
	if (LINEGfxInfo.isSelected)  // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = LINEGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LINEGfxInfo.BorderWdth);  // Set Drawing color & width

	drawstyle style;
	if (LINEGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LINEGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawLine(p3.x, p3.y, p4.x, p4.y, style);
}









void GUI::DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const {
	color DrawingClr;
	if (OvalGfxInfo.isSelected) DrawingClr = HighlightColor;
	else DrawingClr = OvalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth);

	drawstyle style;
	if (OvalGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}

void GUI::DrawRegPoly(int* xPoints, int* yPoints, int vert_num, GfxInfo RegPolyGfxInfo) const {
	color DrawingClr;
	if (RegPolyGfxInfo.isSelected) // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = RegPolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RegPolyGfxInfo.BorderWdth); // Set Drawing color & width

	drawstyle style;
	if (RegPolyGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(RegPolyGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}

	pWind->DrawPolygon(xPoints, yPoints, vert_num, style);
}



void GUI::setcolor(color c)
{
	DrawColor = c;
	// pshape->ChngDrawClr(black); //
}

shape* GUI::Getshape(int x, int y) const {
	return nullptr; // This method should be implemented based on your application logic
}

void GUI::DrawImage(const std::string& imagePath, int x, int y, int width, int height) const {
	pWind->DrawImage(imagePath, x, y, width, height);
}






//void GUI::CopySelectedShapes()
//{// Iterate through selected shapes and create copies
//	for (int i = 0; i < numSelectedShapes; ++i) {
//		// Example: Assuming each shape class has a Clone function
//	/*	shape[numShapes++] = selectedShapes[i]->Clone(); */ // Implement Clone() in your shape classes
//	}
//}
//
//void GUI::CutSelectedShapes() {
//	int newIndex = 0; // Index for reshuffling shapes array after cutting
//
//	// Iterate through all shapes
//	for (int i = 0; i < numShapes; ++i) {
//		// Check if the current shape is selected
//		//if (shapes[i]->IsSelected()) {
//		//	// Move the selected shape to the selectedShapes array
//		//	selectedShapes[numSelectedShapes++] = shapes[i];
//		//}
//		//else {
//		//	// If not selected, keep it in the shapes array (reshuffle)
//		//	shapes[newIndex++] = shapes[i];
//		//}
//	}
//
//	// Update the number of shapes after cutting
//	numShapes = newIndex;
//}
//void GUI::PasteShapes() {
//	// Example: Assuming you have copiedShapes array to store copied shapes
//	for (int i = 0; i < numCopiedShapes; ++i) {
//		// Example: Assuming each shape class has a CreateCopy function
//		/*shapes[numShapes++] = copiedShapes[i]->Clone(); */ // Implement Clone() in your shape classes
//	}
//}
//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

