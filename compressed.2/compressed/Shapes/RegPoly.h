
#pragma once

#include "shape.h"
#include <vector>
#include <string>

class RegPoly : public shape {
private:
    Point Corner1;
    Point Corner2;
    int vert_num;
    std::vector<Point> Vertices; // Vector to hold the vertices of the polygon
    std::string imagePath; // Path to the image
public:
    RegPoly(Point, Point, int vert_num, GfxInfo shapeGfxInfo);
    virtual ~RegPoly();
    virtual void Save(ofstream& outfile);
    virtual void Draw(GUI* pUI) const;
    void SetImage(const std::string& imagePath);
    bool ISinside(int x, int y)  override;
    void CalculateVertices();
    void Zoom(double scaleFactor); // Add this method
    virtual void PrintInfo(GUI* pUI)  override;
    virtual void Load(ifstream& Infile)override;
    virtual void Resize(double size)override;
};