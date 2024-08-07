#pragma once
#include "Shape.h"
#include <fstream>

using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
	enum { maxShapeCount = 1000 };
private:
	shape* shapesList[maxShapeCount]; //a container to hold all shapes							   
	int shapeCount;			// Actual number of shapes stored in the list
	shape* selectedShape;	//pointer to the currently selected shape
	bool saved;
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void Delete();
	void setsaved(bool s); //exit
	bool getsaved();
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	shape* getselectedshape() ;
	void Zoom(double scaleFactor); // Add this method
	void Save(ofstream& OF);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	void Exit();
	color getcolor();
	GUI* Pgui;
};
