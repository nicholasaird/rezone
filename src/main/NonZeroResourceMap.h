#ifndef NOZEROMAP_HPP
#define NOZEROMAP_HPP

#include <map>

#include "Resource.h"

class NonZeroResourceMap {
public:
    typedef std::map<Resource, int>::const_iterator const_iterator;
private:
    std::map<Resource, int> map;

public:
    NonZeroResourceMap();
    NonZeroResourceMap(std::map<Resource, int> map);
    int get(Resource resource) const;
    void set(Resource resource, int val);

    bool operator==(const NonZeroResourceMap& rhs) const;
    bool operator!=(const NonZeroResourceMap& rhs) const;

    const_iterator begin() const;
    const_iterator end() const;
private:
    void removeZeros();
    void removeIfZero(Resource resource, int val);
};

#endif
