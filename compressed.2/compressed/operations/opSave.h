#pragma once
#include "operation.h"

class opSave : public operation
{
public:
	opSave(controller* pCont);
	~opSave();
	virtual void Execute();
};


