#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.h"
#include "Stock.h"
#include "StockPair.h"
#include "Utility.h"

class Zone {
private:
    StockPair recipe;
public:
    Zone(StockPair recipe);
    virtual ~Zone();
    Stock getInputMet();
    Stock getInputCap();
    Stock getOutputCap();
    void update(Stock relief);
};
#endif
