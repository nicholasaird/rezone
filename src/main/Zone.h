#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.h"
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
    Stock getInputMet();
    Stock getInputAvailable();
    Stock getInputCap();
    Stock getOutputMet();
    Stock getOutputAvailable();
    Stock getOutputCap();
    void update(Stock& relief);
    void supplyInput(Stock supply);
    void takeOutput(Stock consumption);
    void cancelInput(Stock cancelConsumption);
    void cancelOutput(Stock cancelConsumption);
};
#endif
