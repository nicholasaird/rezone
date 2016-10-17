#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.h"
#include "Stock.h"
#include "StockPair.h"
#include "Utility.h"

class Zone {
private:
    StockPair recipe;
    Stock input;
    Stock output;
    Stock inputCap;
    Stock outputCap;
public:
    Zone(StockPair recipe);
    virtual ~Zone();
    Stock getInputMet();
    Stock getInputCap();
    Stock getOutputCap();
    void update(Stock& relief);
    void supplyInput(Stock supply);
    void takeOutput(Stock consumption);
};
#endif
