#ifndef RESZONE_HPP
#define RESZONE_HPP

#include "Resource.hpp"
#include "Zone.hpp"

class ResZone : public Zone {
public:
    ResZone();
    int getNumProduced(Resource resource) override;
};

#endif
