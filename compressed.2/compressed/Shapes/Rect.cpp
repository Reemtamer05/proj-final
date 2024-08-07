#include "Rect.h"
#include<fstream>
Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

bool Rect::ISinside(int x, int y)
{
	return (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y);
}


void Rect::Save(ofstream& outfile)
{
	outfile << "Rectangle" << "\t"
		<< ID << "\t"
		<< Corner1.x << "\t" << Corner1.y << "\t"
		<< Corner2.x << "\t" << Corner2.y << "\t"
		<< int(ShpGfxInfo.DrawClr.ucRed) << "\t"
		<< int(ShpGfxInfo.DrawClr.ucGreen) << "\t"
		<< int(ShpGfxInfo.DrawClr.ucBlue) << "\t";
	if (ShpGfxInfo.isFilled) {
		outfile << int(ShpGfxInfo.FillClr.ucRed) << "\t"
			<< int(ShpGfxInfo.FillClr.ucGreen) << "\t"
			<< int(ShpGfxInfo.FillClr.ucBlue) << "\t";
	}
	else {
		outfile << "notfilled" << "\t"
			<< "notfilled" << "\t"
			<< "notfilled" << "\t";
	}
	outfile << ShpGfxInfo.BorderWdth << endl;
}



void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

void Rect::PrintInfo(GUI* pUI)
{
}

void Rect::Load(ifstream& Infile)
{
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	Infile >> ShpGfxInfo.DrawClr.ucRed >> ShpGfxInfo.DrawClr.ucGreen >> ShpGfxInfo.DrawClr.ucBlue;
	Infile >> ShpGfxInfo.FillClr.ucRed >> ShpGfxInfo.FillClr.ucGreen >> ShpGfxInfo.FillClr.ucBlue;
	Infile >> ShpGfxInfo.isFilled >> ShpGfxInfo.BorderWdth >> ShpGfxInfo.isSelected;
}

void Rect::Resize(double size)
{
	int width = Corner2.x - Corner1.x;
	int height = Corner2.y - Corner1.y;
	int newWidth = static_cast<int>(width * size);
	int newHeight = static_cast<int>(height * size);

	Corner2.x = Corner1.x + newWidth;
	Corner2.y = Corner1.y + newHeight;
}
