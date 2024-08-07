#pragma once
#include "shape.h"
class triangle :public shape {
private:
	Point vertix1;
	Point vertix2;
	Point vertix3;
	double area(Point a, Point b, Point c) const
	{
		return std::abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
	}
public:
	triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~triangle();
	bool ISinside(int x, int y)override;
	virtual void Save(ofstream& outfile)override;
	virtual void Draw(GUI* pUI) const override;
	virtual void PrintInfo(GUI* pUI)  override;
	virtual void Load(ifstream& Infile)override;
	virtual void Resize(double size)override;
	//virtual shape* Clone() const override {}
};

