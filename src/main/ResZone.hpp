#ifndef RESZONE_HPP
#define RESZONE_HPP

#include "Resource.hpp"
#include "Zone.hpp"

class ResZone : public Zone {
public:
    ResZone();
    ~ResZone() override;
    int getProductionTotal(Resource resource) override;
    int getProductionUnused(Resource resource) override;
};

#endif
