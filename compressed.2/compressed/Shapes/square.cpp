#include "square.h"
#include<fstream>
using namespace std;

square::square(Point s1, int l, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{

	s = s1;
	slength = l;
	
}

square::~square()
{
}



void square::Save(ofstream& outfile)
{
	outfile << "Square" << "\t"
		<< ID << "\t"
		<< s.x << "\t" << s.y << "\t"
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



bool square::ISinside(int x, int y)
{
	return (x >= s.x && x <= s.x + slength && y >= s.y && y <= s.y + slength);
}



void square::Draw(GUI* pUI) const
{
	pUI->DrawSQR(s, slength, ShpGfxInfo);
}

void square::PrintInfo(GUI* pUI)
{
	pUI->PrintMessage("square");
}

void square::Load(ifstream& Infile)
{
	Infile >> s.x >> s.y ;
	Infile >> ShpGfxInfo.DrawClr.ucRed >> ShpGfxInfo.DrawClr.ucGreen >> ShpGfxInfo.DrawClr.ucBlue;
	Infile >> ShpGfxInfo.FillClr.ucRed >> ShpGfxInfo.FillClr.ucGreen >> ShpGfxInfo.FillClr.ucBlue;
	Infile >> ShpGfxInfo.isFilled >> ShpGfxInfo.BorderWdth >> ShpGfxInfo.isSelected;
}


void square::Resize(double size) {
	if (size <= 0)
		return;

	// Calculate the new length
	int newLength = static_cast<int>(slength * size);

	// Update the length
	slength = newLength;
}
