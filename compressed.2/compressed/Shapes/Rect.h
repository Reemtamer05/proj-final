#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	bool ISinside(int x, int y)override;
	virtual void Save(ofstream& outfile);
	virtual void Draw(GUI* pUI) const;
	virtual void PrintInfo(GUI* pUI)  override;
	virtual void Load(ifstream& Infile)override;
	virtual void Resize(double size)override;
};

