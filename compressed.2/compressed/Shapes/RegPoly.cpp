
#include "RegPoly.h"
#include <cmath>
#include<fstream>


const double PI = 3.14;

RegPoly::RegPoly(Point P1, Point P2, int vert_num, GfxInfo shapeGfxInfo)
    : shape(shapeGfxInfo), Corner1(P1), Corner2(P2), vert_num(vert_num) {
    CalculateVertices();
}

RegPoly::~RegPoly() {}

void RegPoly::CalculateVertices() {
    Vertices.clear();
    Point center = Corner1;
    double radius = sqrt(pow(Corner2.x - Corner1.x, 2) + pow(Corner2.y - Corner1.y, 2));
    double angleIncrement = 2 * PI / vert_num;
    for (int i = 0; i < vert_num; ++i) {
        double angle = i * angleIncrement;
        Point vertex;
        vertex.x = center.x + radius * cos(angle);
        vertex.y = center.y + radius * sin(angle);
        Vertices.push_back(vertex);
    }
}

void RegPoly::Draw(GUI* pUI) const {
    // Convert vector of vertices to arrays for the drawing function
    std::vector<int> xPoints(vert_num);
    std::vector<int> yPoints(vert_num);
    for (int i = 0; i < vert_num; ++i) {
        xPoints[i] = Vertices[i].x;
        yPoints[i] = Vertices[i].y;
    }
    pUI->DrawRegPoly(xPoints.data(), yPoints.data(), vert_num, ShpGfxInfo);

    if (!imagePath.empty()) {
        // Draw the image at the center of the polygon
        Point center = Corner1;
        pUI->DrawImage(imagePath, center.x, center.y, 100, 100); // Adjust size as needed
    }
}

void RegPoly::SetImage(const std::string& imagePath) {
    this->imagePath = imagePath;
}
bool RegPoly::ISinside(int x, int y)  {
    int i, j;
    bool isInside = false;
    for (i = 0, j = vert_num - 1; i < vert_num; j = i++) {
        if (((Vertices[i].y > y) != (Vertices[j].y > y)) &&
            (x < (Vertices[j].x - Vertices[i].x) * (y - Vertices[i].y) / (Vertices[j].y - Vertices[i].y) + Vertices[i].x)) {
            isInside = !isInside;
        }
    }
    return isInside;
}
void RegPoly::Zoom(double scaleFactor) {
    Point center;
    center.x = (Corner1.x + Corner2.x) / 2;
    center.y = (Corner1.y + Corner2.y) / 2;

    double width = abs(Corner2.x - Corner1.x) * scaleFactor;
    double height = abs(Corner2.y - Corner1.y) * scaleFactor;

    Corner1.x = center.x - width / 2;
    Corner1.y = center.y - height / 2;
    Corner2.x = center.x + width / 2;
    Corner2.y = center.y + height / 2;
    CalculateVertices();

}

void RegPoly::Save(ofstream& outfile)
{
    outfile << "Regular polygon" << "\t"
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


void RegPoly::Resize(double size)
{
    if (size <= 0)
        return; // Invalid resize factor

    // Calculate the center of the polygon
    Point center = Corner1;
    double currentRadius = sqrt(pow(Corner2.x - center.x, 2) + pow(Corner2.y - center.y, 2));
    double newRadius = currentRadius * size;

    // Update vertices
    Vertices.clear();
    double angleIncrement = 2 * PI / vert_num;
    for (int i = 0; i < vert_num; ++i) {
        double angle = i * angleIncrement;
        Point vertex;
        vertex.x = center.x + newRadius * cos(angle);
        vertex.y = center.y + newRadius * sin(angle);
        Vertices.push_back(vertex);
    }

}


void RegPoly::Load(ifstream& Infile) {
    Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
    Infile >> ShpGfxInfo.DrawClr.ucRed >> ShpGfxInfo.DrawClr.ucGreen >> ShpGfxInfo.DrawClr.ucBlue;
    Infile >> ShpGfxInfo.FillClr.ucRed >> ShpGfxInfo.FillClr.ucGreen >> ShpGfxInfo.FillClr.ucBlue;
    Infile >> ShpGfxInfo.isFilled >> ShpGfxInfo.BorderWdth >> ShpGfxInfo.isSelected;
}

void RegPoly::PrintInfo(GUI* pUI)
{
}
