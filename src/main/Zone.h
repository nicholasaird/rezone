#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.h"
#include "Stock.h"
#include "Utility.h"

class Zone {
private:
    int level;
    bool connectedToElectricity;
    // bool connectedToWater;
    Stock productionTotal;
    Stock productionUsed;
public:
    Zone();
    virtual ~Zone();
    Stock getProductionTotal();
    Stock getProductionUnused();
    // virtual int getConsumptionNeeded(Resource resource) = 0;
    // virtual int getConsumptionMet(Resource resource) = 0;
    bool isConnectedTo(Utility utility);
    void setConnectedTo(Utility utility, bool connected);
    // virtual bool getUtilityNeeded(Utility utility) = 0;
    // virtual bool getUtilityMet(Utility utility) = 0;
    void updateLevel();
    int getLevel();
    void setLevel(int level);
};

#endif
