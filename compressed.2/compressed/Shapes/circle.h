#pragma once
#include "shape.h"

class circle :public shape {
private:
	Point center;
	int radius = 50;

public:
	circle(Point, GfxInfo shapeGfxInfo);
	circle(circle * c);
	virtual ~circle();
	virtual void Draw(GUI* pUI)  const;
	virtual void Save(ofstream& outfile) ;

	void PrintInfo(GUI* pUI) override;
	virtual void Load(ifstream& Infile)override;
	virtual void Resize(double size)override;
};


