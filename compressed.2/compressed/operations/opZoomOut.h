#pragma once

#include "operation.h"

// Class representing the Zoom Out operation
class opZoomOut : public operation {
public:
    opZoomOut(controller* pCont); // Constructor
    virtual ~opZoomOut();         // Destructor
    virtual void Execute();       // Execute the operation
};
