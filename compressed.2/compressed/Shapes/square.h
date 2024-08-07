#pragma once
#include "shape.h"
class square :public shape {
private:
	Point s;
	int slength;
public:
	square(Point, int l, GfxInfo shapeGfxInfo);
	virtual ~square();
	bool ISinside(int x, int y)override;
	virtual void Save(ofstream& outfile);
	virtual void Draw(GUI* pUI) const;
	virtual void PrintInfo(GUI* pUI)  override;
	virtual void Load(ifstream& Infile)override;
	virtual void Resize(double size)override;
};

