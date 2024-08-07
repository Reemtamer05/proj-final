#include "triangle.h"
#include<fstream>
triangle::triangle(Point v1, Point v2, Point v3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	vertix1 = v1;
	vertix2 = v2;
	vertix3 = v3;

}

triangle::~triangle()
{
}

bool triangle::ISinside(int x, int y)
{
	Point P{ x, y };
	double areaOrig = area(vertix1, vertix2, vertix3);
	double area1 = area(P, vertix2, vertix3);
	double area2 = area(vertix1, P, vertix3);
	double area3 = area(vertix1, vertix2, P);

	// Check if sum of area1, area2 and area3 is same as areaOrig
	return std::abs(areaOrig - (area1 + area2 + area3)) < 1e-6;
}

void triangle::Save(ofstream& outfile)
{
	outfile << "Triangle" << "\t"
		<< ID << "\t"
		<< vertix1.x << "\t" << vertix1.y << "\t"
		<< vertix2.x << "\t" << vertix2.y << "\t"
		<< vertix3.x << "\t" << vertix3.y << "\t"
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


void triangle::Draw(GUI* pUI) const
{
	pUI->DrawTRI(vertix1, vertix2, vertix3, ShpGfxInfo);
}

void triangle::PrintInfo(GUI* pUI)
{
	pUI->getCrntFillColor();
	\
}

void triangle::Load(ifstream& Infile)
{
	Infile >> vertix1.x >> vertix1.y >> vertix2.x >> vertix2.y >> vertix3.x >> vertix3.y;
	Infile >> ShpGfxInfo.DrawClr.ucRed >> ShpGfxInfo.DrawClr.ucGreen >> ShpGfxInfo.DrawClr.ucBlue;
	Infile >> ShpGfxInfo.FillClr.ucRed >> ShpGfxInfo.FillClr.ucGreen >> ShpGfxInfo.FillClr.ucBlue;
	Infile >> ShpGfxInfo.isFilled >> ShpGfxInfo.BorderWdth >> ShpGfxInfo.isSelected;
}

void triangle::Resize(double size)
{
	Point centroid;
	centroid.x = (vertix1.x + vertix2.x + vertix3.x) / 3;
	centroid.y = (vertix1.y + vertix2.y + vertix3.y) / 3;

	// Scale each vertex relative to the centroid
	vertix1.x = centroid.x + static_cast<int>((vertix1.x - centroid.x) * size);
	vertix1.y = centroid.y + static_cast<int>((vertix1.y - centroid.y) * size);

	vertix2.x = centroid.x + static_cast<int>((vertix2.x - centroid.x) * size);
	vertix2.y = centroid.y + static_cast<int>((vertix2.y - centroid.y) * size);

	vertix3.x = centroid.x + static_cast<int>((vertix3.x - centroid.x) * size);
	vertix3.y = centroid.y + static_cast<int>((vertix3.y - centroid.y) * size);
}


