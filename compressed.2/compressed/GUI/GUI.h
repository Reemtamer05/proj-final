#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
#include <string>
#include <vector>

using namespace std;

class shape;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};



class GUI
{
	enum MenuIcon //The icons of the menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_TRI,		//Triangle icon in menu

		//TODO: Add more icons names here



		ICON_CIRCLE, // Circle icon
		ICON_LINE,   // Line icon
		ICON_SQR,
		ICON_OVAL,
		ICON_REGPOLY,
		ICON_FILL,   // Fill color icon
		ICON_PEN,    // Pen color icon
		ICON_SAVE,   // Save icon
		ICON_LOAD,   // Load icon 
		ICON_STICK,
		ICON_DEL,
		ICON_RES,
		ICON_MOVE,
		ICON_ROT,
		ICON_SEND,
		ICON_BRING,
		ICON_DRAW,
		ICON_PLAY,
		ICON_SELECT,
		ICON_COPY,
		ICON_PASTE,
		ICON_CUT,
		ICON_ZOMIN,
		ICON_ZOMOUT,
		ICON_EXIT,   // Exit icon


		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};




	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void Drawcircle(Point center, int radius, GfxInfo CircleGfxInfo) const;
	/*void DrawTRI(Point vertix1, Point vertix2, Point vertix3, GfxInfo TRIGfxInfo) const;*/
	void DrawTRI(Point vertix1, Point vertix2, Point vertix3, GfxInfo TRIGfxInfo) const;
	void DrawSQR(Point s, int slength, GfxInfo SQRGfxInfo) const;
	void DrawLINE(Point p3, Point p4, GfxInfo LINEGfxInfo) const;
	void DrawOval(Point P1, Point P2, GfxInfo RectGfxInfo) const;
	void DrawRegPoly(int* xPoints, int* yPoints, int vert_num, GfxInfo RegPolyGfxInfo) const;
	void DrawImage(const std::string& imagePath, int x, int y, int width, int height) const; // Add this declaration

	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void setcolor(color c);
	shape* Getshape(int x, int y) const; // Add the declaration here
	color getcolor();
	void SetPenWidth(int width);
	void SetFillClr(color NewClr);


	//static const int MAX_SHAPES = 100;  //  Maximum number of shapes
	//shape* shapes[MAX_SHAPES];          // Array to store all shapes on the screen
	//int  numShapes;                      // Number of shapes currently in shapes[]
	//static const int MAX_COPIED_SHAPES = 10;
	//static const int MAX_SELECTED_SHAPES = 10;  //  Maximum number of selected shapes
	//shape* selectedShapes[MAX_SELECTED_SHAPES];  // Array to store selected shapes
	//int numSelectedShapes;
	//shape* copiedShapes[MAX_COPIED_SHAPES]; // Array to store copied shapes
	//int numCopiedShapes; // Number of shapes copied
	//shape* selectedShapes[MAX_SELECTED_SHAPES]; // Array to store selected shapes
	//int numSelectedShapes; // Number of shapes selected
	//GUI() : numShapes(0), numSelectedShapes(0) {}

	//// Function to copy selected shapes
	//void CopySelectedShapes();

	//// Function to cut selected shapes
	//void CutSelectedShapes();

	//// Function to paste copied shapes
	//void PasteShapes();


	~GUI();
};

