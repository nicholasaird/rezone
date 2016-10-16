#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.hpp"
#include "ResourceCount.hpp"
#include "Utility.hpp"

class Zone {
private:
    int level;
    bool connectedToElectricity;
public:
    Zone();
    virtual ~Zone();
    virtual int getProductionTotal(Resource resource) = 0;
    virtual int getProductionUnused(Resource resource) = 0;
    bool isConnectedTo(Utility utility);
    void setConnectedTo(Utility utility, bool connected);
    void updateLevel();
    int getLevel();
    void setLevel(int level);
};

#endif
