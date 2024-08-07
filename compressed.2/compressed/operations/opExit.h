#pragma once

#include "operation.h"

class opExit : public operation {
public:
	opExit(controller* pCont);
	virtual ~opExit();
	// Execute selection operation

	virtual void Execute();
};
