#include "Graph.h"
#include "../GUI/GUI.h"
#include "../shapes/RegPoly.h"
#include "../shapes/Oval.h"
#include <fstream>
#include "Rect.h"
#include<iostream>
#include "Line.h"
#include "Circle.h"
#include "Triangle.h"
#include"square.h"

Graph::Graph()
{
	shapeCount = 0;
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes list
	if(shapeCount<maxShapeCount)
		shapesList[shapeCount++] = pShp;
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (int i=0;i<shapeCount; i++)
		shapesList[i]->Draw(pUI);
}




void Graph::Delete() {

	for (int i = 0; i < shapeCount; i++) {  //for loop bet3ady 3ala el shapes
		if (shapesList[i]->IsSelected()) {  //ba3deen betekhtar lw elshape el 3andy is selected
			delete shapesList[i];  // ye3ml delete llshape
			for (int j = i; j < shapeCount; j++) {  //ba3d ma ye3ml delete el shape el etmasah byseeb makano fady fa 3ayzeen neraga3 el makan el shapes el 3ando lwara wahed 3swhan mayb2ash fe makan fady
				shapesList[j] = shapesList[j + 1];  //3amla loop gdeeda b j bet3ady 3ala el shapes el mawgooda ba3deen betdy el shapes el ba3d raqam el shape eletmasah raqamhom plus one fa masaln makan el shape elrabe3 hayb2a el shape elrabe3 plus one aka elshape elkhames
			}
			shapeCount--;  //ba3deen el shape count by2l ba3d ma el shape etmasah
		}
	}
}



void Graph::setsaved(bool s) {
	saved = s;
}

bool Graph::getsaved() {
	return saved;
}


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	

	for (shape* s : shapesList)
	{
		s->SetSelected(false);
	}

	shape* selectedShape = nullptr;
	for (int i = shapeCount - 1; i >= 0; i--)
	{
		if (shapesList[i]->ISinside(x, y))
		{
			selectedShape = shapesList[i];
			break;
		}
	}

	if (selectedShape != nullptr)
	{
		selectedShape->SetSelected(true);
		Pgui->PrintMessage("Shape selected: ");
		selectedShape->PrintInfo(Pgui);
	}

	return nullptr;
}

shape* Graph::getselectedshape()
{
	return nullptr;
}

color Graph::getcolor()
{
	return color();
}

void Graph::Save(ofstream& OF) 
{
	for (int i = 0; i < shapeCount; i++)
	{
		shapesList[i]->Save(OF);
		
	}
}

void Graph::load(ifstream& inputfile)
{
	ifstream infile;
	/*if (!inFile)
	{
		cout << "Cannot open file: " << filename << std::endl;
		return;
	}*/

	string shapeType;
	while (infile >> shapeType)
	{
		if (shapeType == "RECTANGLE")
		{
			GfxInfo gfxInfo;
			Rect* rect = new Rect(Point(), Point(), gfxInfo);
			rect->Load(inputfile);
			/*shape.push_back(rect);*/
		}
		else if (shapeType == "CIRCLE")
		{
			GfxInfo gfxInfo;
			circle* crc = new circle(Point(), gfxInfo);
			crc->Load(inputfile);
			/* shapes.push_back(circle);*/
		}
		else if (shapeType == "LINE")
		{
			GfxInfo gfxInfo;
			Line* line = new Line(Point(), Point(), gfxInfo);
			line->Load(inputfile);
			/*shapes.push_back(line);*/
		}
		else if (shapeType == "square") {
			GfxInfo gfxInfo;
			square* sqr = new square(Point(), 50, gfxInfo);
			sqr->Load(inputfile);

		}
		else if (shapeType == "triangle") {
			GfxInfo gfxInfo;
			triangle* tri = new triangle(Point(), Point(), Point(), gfxInfo);
			tri->Load(inputfile);
		}
		else if (shapeType == "reg polygon") {
			GfxInfo gfxInfo;
			RegPoly* poly = new RegPoly(Point(), Point(), 3, gfxInfo);
			poly->Load(inputfile);
		}
		// Add cases for other shapes
	}

	infile.close();
}

void Graph::Exit()
{
	for (int i = 0; i < shapeCount; i++)
	{
		delete shapesList;
		shapesList[i] = nullptr;
	}
	/*if (selectedshape) {
		selectedshape = nullptr;*/
	//}
}



void Graph::Zoom(double scaleFactor) {
	for (shape* shp : shapesList) {
		Oval* ovalShape = dynamic_cast<Oval*>(shp);
		if (ovalShape != nullptr) {
			ovalShape->Zoom(scaleFactor);
			continue;
		}

		RegPoly* regPolyShape = dynamic_cast<RegPoly*>(shp);
		if (regPolyShape != nullptr) {
			regPolyShape->Zoom(scaleFactor);
			continue;
		}

		// Implement similar logic for other shapes as needed
	}
}


