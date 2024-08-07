#include "line.h"
#include <fstream>
Line::Line(Point d1, Point d2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	dot1 = d1;
	dot2 = d2;
}

Line::Line(Line* l) :shape(l->ShpGfxInfo)// bakhod object w ka2eno l line gdeed ba3deen bakhod el parameters beto3 el line ahotaha fl object el gdeed lline 3shan a3mlo copy
{
	dot1 = l->dot1;
	dot2 = l->dot2;
}

Line::~Line()
{
}

void Line::Draw(GUI* pUI) const
{
	pUI->DrawLINE(dot1, dot2, ShpGfxInfo);
}

void Line::Save(ofstream& outfile)
{
	outfile << "line" << "\t"
		<< ID << "\t"
		<< dot1.x << "\t" << dot1.y << "\t" //
		<< dot2.x << "\t" << dot2.y << "\t"
		<< int(ShpGfxInfo.DrawClr.ucRed) << "\t"  //3andy 3 alwan ahmar w akhdar w azra2 homa dol el 3 alwan el asasyeen el bykaweno aw loon fa 3shan yetla3 feh loon lazem yeb2a el talat alwan dol mawgodeen b ekhtelaf ratios w number code l kol raqam
		<< int(ShpGfxInfo.DrawClr.ucGreen) << "\t"
		<< int(ShpGfxInfo.DrawClr.ucBlue) << "\t";
	if (ShpGfxInfo.isFilled) { //3shan momken ye3ml fill llshape w momken laa
		outfile<<int(ShpGfxInfo.FillClr.ucRed) << "\t"
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

bool Line::ISinside(int x, int y)
{
	int dx = dot2.x - dot1.x;
	int dy = dot2.y - dot1.y;
	int len = sqrt(dx * dx + dy * dy);
	int projection = ((x - dot1.x) * dx + (y - dot1.y) * dy) / len;
	if (projection < 0 || projection > len) return false;
	int perpDist = abs((x - dot1.x) * dy - (y - dot1.y) * dx) / len;
	return perpDist < 5;
}


//bool Line::ISinside(int x, int y)
//{
//	int dx = dot2.x - dot1.x;
//	int dy = dot2.y - dot1.y;
//	int len = sqrt(dx * dx + dy * dy);
//	int projection = ((x - dot1.x) * dx + (y - dot1.y) * dy) / len;
//	if (projection < 0 || projection > len) return false;
//	int perpDist = abs((x - dot1.x) * dy - (y - dot1.y) * dx) / len;
//	return perpDist < 5;
//}


void Line::PrintInfo(GUI* pUI)
{
	pUI->getCrntFillColor();
}

void Line::Load(ifstream& Infile)
{
	Infile >> dot1.x >> dot1.y >> dot2.x >> dot2.y;
	Infile >> ShpGfxInfo.DrawClr.ucRed >> ShpGfxInfo.DrawClr.ucGreen >> ShpGfxInfo.DrawClr.ucBlue;
	Infile >> ShpGfxInfo.FillClr.ucRed >> ShpGfxInfo.FillClr.ucGreen >> ShpGfxInfo.FillClr.ucBlue;
	Infile >> ShpGfxInfo.isFilled >> ShpGfxInfo.BorderWdth >> ShpGfxInfo.isSelected;
}

void Line::Resize(double size)
{
	int dx = dot2.x - dot1.x;
	int dy = dot2.y - dot1.y;
	dot2.x = dot1.x + static_cast<int>(dx * size);
	dot2.y = dot1.y + static_cast<int>(dy * size);
}



