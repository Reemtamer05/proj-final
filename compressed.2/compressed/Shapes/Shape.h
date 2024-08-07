#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;
	//Each shape has an ID
	static int nextID;
	GfxInfo ShpGfxInfo;	//shape graphis info
	
	/// Add more parameters if needed.
	bool selected;
public:
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {} 
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	virtual bool ISinside(int x, int y);
	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color

	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the shape
	virtual void Resize(double size) ;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	virtual void Save(ofstream& outfile) ;	//Save the shape parameters to the file
	virtual void Load(ifstream &Infile) ;	//Load the shape parameters to the file
	void Setfillclr(bool s);

	void changeBorderColor(color c);
	virtual void PrintInfo(GUI* pUI) = 0;	//print all shape info on the status bar
};

