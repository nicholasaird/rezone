#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.hpp"
#include "ResourceCount.hpp"
#include "Utility.hpp"

class Zone {
private:
    int level;
    bool connectedToElectricity;
    ResourceCount productionTotal;
    ResourceCount productionUsed;
public:
    Zone();
    virtual ~Zone();
    ResourceCount getProductionTotal();
    ResourceCount getProductionUnused();
    bool isConnectedTo(Utility utility);
    void setConnectedTo(Utility utility, bool connected);
    void updateLevel();
    int getLevel();
    void setLevel(int level);
};

#endif
