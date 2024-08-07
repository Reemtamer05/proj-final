#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
    ID = nextID++;
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

bool shape::ISinside(int x, int y)
{
    return false;
}


void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}


void shape::Resize(double size)
{
}

void shape::Save(ofstream& outfile)
{
}

void shape::Load(ifstream& Infile)
{
}

void shape::Setfillclr(bool s)
{
    selected = s;
    ShpGfxInfo.isSelected = s;
    if (selected)
    {
        ShpGfxInfo.FillClr = BLUE;
    }
    else
    {
        ShpGfxInfo.FillClr = WHITE;
    }
    ShpGfxInfo.isSelected = s;
}

void shape::changeBorderColor(color c)
{
    ShpGfxInfo.DrawClr = c;
}

int shape::nextID = 1;
