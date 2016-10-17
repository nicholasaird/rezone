#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.h"
#include "Stock.h"
#include "Utility.h"

class Zone {
private:
    Stock productionTotal;
    Stock productionUsed;
public:
    Zone();
    virtual ~Zone();
    Stock getProductionTotal();
    Stock getProductionUnused();
};
#endif
