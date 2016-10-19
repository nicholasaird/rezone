#include "NonZeroResourceMap.h"

NonZeroResourceMap::NonZeroResourceMap()
: map()
{
    //
}

NonZeroResourceMap::NonZeroResourceMap(std::map<Resource, int> map)
    : map(map)
{
    removeZeros();
}

void NonZeroResourceMap::removeZeros() {
    for(auto& pair : map) {
        removeIfZero(pair.first, pair.second);
    }
}

void NonZeroResourceMap::removeIfZero(Resource resource, int val) {
    if(val == 0) {
        map.erase(resource);
    }
}

int NonZeroResourceMap::get(Resource resource) const{
    if(map.count(resource) > 0) {
        return map.at(resource);
    }
    else {
        return 0;
    }
}

void NonZeroResourceMap::set(Resource resource, int val){
    map[resource] = val;

    removeIfZero(resource, val);
}

bool NonZeroResourceMap::operator==(const NonZeroResourceMap& rhs) const {
    return map == rhs.map;
}

bool NonZeroResourceMap::operator!=(const NonZeroResourceMap& rhs) const {
    return !(*this == rhs);
}

// NonZeroResourceMap::iterator NonZeroResourceMap::begin() {
//     return map.begin();
// }
//
// NonZeroResourceMap::iterator NonZeroResourceMap::end() {
//     return map.end();
// }

NonZeroResourceMap::const_iterator NonZeroResourceMap::begin() const {
    return map.begin();
}

NonZeroResourceMap::const_iterator NonZeroResourceMap::end() const {
    return map.end();
}
