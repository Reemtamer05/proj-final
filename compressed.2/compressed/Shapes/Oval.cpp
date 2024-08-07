
#include <fstream>
#include "Oval.h"
#include <cmath>

Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo) {
    Corner1 = P1;
    Corner2 = P2;
}

Oval::~Oval() {}

void Oval::Draw(GUI* pUI) const {
    pUI->DrawOval(Corner1, Corner2, ShpGfxInfo);

    if (!imagePath.empty()) {
        Point center;
        center.x = (Corner1.x + Corner2.x) / 2;
        center.y = (Corner1.y + Corner2.y) / 2;
        pUI->DrawImage(imagePath, center.x, center.y, 100, 100); // Adjust size as needed
    }
}

void Oval::SetImage(const std::string& imagePath) {
    this->imagePath = imagePath;
}

bool Oval::IsPointInside(int x, int y) const {
    Point center;
    center.x = (Corner1.x + Corner2.x) / 2;
    center.y = (Corner1.y + Corner2.y) / 2;

    double a = abs(Corner2.x - Corner1.x) / 2.0;
    double b = abs(Corner2.y - Corner1.y) / 2.0;

    double dx = x - center.x;
    double dy = y - center.y;

    return ((dx * dx) / (a * a) + (dy * dy) / (b * b)) <= 1.0;
}

void Oval::Zoom(double scaleFactor) {
    Point center;
    center.x = (Corner1.x + Corner2.x) / 2;
    center.y = (Corner1.y + Corner2.y) / 2;

    double width = abs(Corner2.x - Corner1.x) * scaleFactor;
    double height = abs(Corner2.y - Corner1.y) * scaleFactor;

    Corner1.x = center.x - width / 2;
    Corner1.y = center.y - height / 2;
    Corner2.x = center.x + width / 2;
    Corner2.y = center.y + height / 2;
}

void Oval::Save(ofstream& outfile)
{
    outfile << "Oval" << "\t"
        << ID << "\t"
        << Corner1.x << "\t" << Corner1.y << "\t" //
        << Corner2.x << "\t" << Corner2.y << "\t"
        << int(ShpGfxInfo.DrawClr.ucRed) << "\t"  //3andy 3 alwan ahmar w akhdar w azra2 homa dol el 3 alwan el asasyeen el bykaweno aw loon fa 3shan yetla3 feh loon lazem yeb2a el talat alwan dol mawgodeen b ekhtelaf ratios w number code l kol raqam
        << int(ShpGfxInfo.DrawClr.ucGreen) << "\t"
        << int(ShpGfxInfo.DrawClr.ucBlue) << "\t";
    if (ShpGfxInfo.isFilled) { //3shan momken ye3ml fill llshape w momken laa
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


void Oval::PrintInfo(GUI* pUI)
{
}