#ifndef ZONE_HPP
#define ZONE_HPP

#include "Resource.hpp"

class Zone {
public:
    Zone();
    virtual int getNumProduced(Resource resource) = 0;
};

#endif
