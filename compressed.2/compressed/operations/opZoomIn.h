#pragma once

#include "operation.h"

// Class representing the Zoom In operation
class opZoomIn : public operation {
public:
    opZoomIn(controller* pCont); // Constructor
    virtual ~opZoomIn();         // Destructor
    virtual void Execute();      // Execute the operation
};

