#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.h"
#include "ResourceException.h"
#include "Stock.h"
#include "StockPair.h"
#include "Utility.h"

class Zone {
private:
    StockPair recipe;
    Stock inputCap;
    Stock outputCap;
    Stock inputMet;
    Stock outputMet;
public:
    Zone(StockPair recipe);
    virtual ~Zone();
    Stock getProvided();
    Stock getUnprovided();
    Stock getInputCap();
    Stock getTaken();
    Stock getUntaken();
    Stock getOutputCap();
    void update(Stock& relief);
    void provide(Stock supply);
    void take(Stock consumption);
    void unprovide(Stock cancelConsumption);
    void untake(Stock cancelConsumption);
};
#endif
