#pragma once
#include "shape.h" 

class Line :public shape {
private:
	Point dot1;
	Point dot2;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	Line(Line* l); //copy constructer b object l 
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile) override;
	bool ISinside(int x, int y)override;
	virtual void PrintInfo(GUI* pUI)  override;
	virtual void Load(ifstream& Infile)override;
	virtual void Resize(double size)override;

};


