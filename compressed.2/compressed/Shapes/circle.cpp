#include "circle.h"
#include<fstream>
circle::circle(Point P1, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	center = P1;
}

circle::circle(circle* c) : shape(c->ShpGfxInfo)
{
	center = c -> center;
}

circle::~circle()
{
}


void circle::Save(ofstream& outfile)
{
	outfile << "circle" << "\t"
		<< ID << "\t"
		<< center.x << "\t" << center.y << "\t"
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

void circle::Draw(GUI* pUI) const
{
	pUI->Drawcircle(center, radius, ShpGfxInfo);
}

void circle::PrintInfo(GUI* pUI)
{
	pUI->getCrntFillColor();
}

void circle::Load(ifstream& Infile)
{
	Infile >> center.x >> center.y >> radius;
	Infile >> ShpGfxInfo.DrawClr.ucRed >> ShpGfxInfo.DrawClr.ucGreen >> ShpGfxInfo.DrawClr.ucBlue;
	Infile >> ShpGfxInfo.FillClr.ucRed >> ShpGfxInfo.FillClr.ucGreen >> ShpGfxInfo.FillClr.ucBlue;
	Infile >> ShpGfxInfo.isFilled >> ShpGfxInfo.BorderWdth >> ShpGfxInfo.isSelected;
}

void circle::Resize(double size)
{
	radius = static_cast<int>(radius * size);
}
