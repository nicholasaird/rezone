#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.h"
#include "Stock.h"
#include "StockPair.h"
#include "Utility.h"

class Zone {
public:
    Zone(StockPair recipe);
    virtual ~Zone();
    Stock getInputMet();
};
#endif
