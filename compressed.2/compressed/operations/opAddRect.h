#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddRect: public operation
{
public:
	opAddRect(controller *pCont);
	virtual ~opAddRect();
	
	//Add rectangle to the controller
	virtual void Execute() ;
	
};

class opAddCRC : public operation {
public:
	opAddCRC(controller* pCont);
	virtual ~opAddCRC();

	// Add rectangle to the controller
	virtual void Execute();
};

class opAddLINE : public operation {
public:
	opAddLINE(controller* pCont);
	virtual ~opAddLINE();

	// Add rectangle to the controller
	virtual void Execute();
};

class opAddSQR : public operation {
public:
	opAddSQR(controller* pCont);
	virtual ~opAddSQR();

	// Add rectangle to the controller
	virtual void Execute();
};

class opAddRegPoly : public operation {
public:
	opAddRegPoly(controller* pCont);
	virtual ~opAddRegPoly();

	// Add rectangle to the controller
	virtual void Execute();
};


class opAddTRI : public operation {
public:
	opAddTRI(controller* pCont);
	virtual ~opAddTRI();

	// Add rectangle to the controller
	virtual void Execute();
};


// Add Oval operation class
class opAddOval : public operation {
public:
	opAddOval(controller* pCont);
	virtual ~opAddOval();

	// Execute operation
	virtual void Execute();
};


//Add ChangeFillColor operation class
class opChangeFillColor : public operation
{
public:
	opChangeFillColor(controller* pCont);
	virtual ~opChangeFillColor();

	//Add rectangle to the controller
	virtual void Execute()override;

};

//Add ChangeDrawColor operation class
class opChangeDrawColor : public operation
{
public:
	opChangeDrawColor(controller* pCont);
	virtual ~opChangeDrawColor();

	//Add rectangle to the controller
	virtual void Execute()override;

};



class opchangebr : public operation
{
private:
	/*Graph* pgraph;
	GUI* PG;*/
public:
	virtual void Execute();
};

class opselect :public operation {

public:
public:
	opselect(controller* pCont);
	virtual ~opselect();

	//Add rectangle to the controller
	virtual void Execute()override;

};
class opaddload :public operation {
public:
	opaddload(controller* pCont);
	virtual ~opaddload();
	virtual void Execute();
};
class opResize :public operation {
public:
	opResize(controller* pCont);
	virtual ~opResize();
	virtual void Execute();
};




