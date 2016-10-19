#ifndef NOZEROMAP_HPP
#define NOZEROMAP_HPP

#include <map>

#include "Resource.h"

class NonZeroResourceMap {
public:
    typedef std::map<Resource, int>::iterator NonZeroResourceMapIterator;
    typedef std::map<Resource, int>::const_iterator NonZeroResourceMapConstIterator;
private:
    std::map<Resource, int> map;

public:
    NonZeroResourceMap();
    NonZeroResourceMap(std::map<Resource, int> map);
    int get(Resource resource) const;
    int set(Resource resource, int val);

    bool operator==(const NonZeroResourceMap& rhs) const;
    bool operator!=(const NonZeroResourceMap& rhs) const;

    NonZeroResourceMapIterator begin();
    NonZeroResourceMapIterator end();
    NonZeroResourceMapConstIterator begin() const;
    NonZeroResourceMapConstIterator end() const;
private:
    void removeZeros();
    void removeIfZero(Resource resource, int val);
};

#endif
