#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.h"
#include "Stock.h"
#include "Utility.h"

class Zone {
public:
    Zone();
    virtual ~Zone();
    Stock getInputMet();
};
#endif
