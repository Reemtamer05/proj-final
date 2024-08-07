#pragma once

#include "shape.h"
#include <string>

class Oval : public shape {
private:
    Point Corner1;
    Point Corner2;
    std::string imagePath;
public:
    Oval(Point, Point, GfxInfo shapeGfxInfo);
    virtual ~Oval();
    virtual void Draw(GUI* pUI) const;
    virtual void Save(ofstream& outfile) ;
    void SetImage(const std::string& imagePath);
    bool IsPointInside(int x, int y) const;
    void Zoom(double scaleFactor); // Add this method
    virtual void PrintInfo(GUI* pUI)  override;
   
};

