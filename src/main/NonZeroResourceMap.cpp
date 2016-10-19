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

int NonZeroResourceMap::set(Resource resource, int val){
    return map[resource] = val;

    removeIfZero(resource, val);
}

bool NonZeroResourceMap::operator==(const NonZeroResourceMap& rhs) const {
    return map == rhs.map;
}

bool NonZeroResourceMap::operator!=(const NonZeroResourceMap& rhs) const {
    return !(*this == rhs);
}

NonZeroResourceMap::NonZeroResourceMapIterator NonZeroResourceMap::begin() {
    return map.begin();
}

NonZeroResourceMap::NonZeroResourceMapIterator NonZeroResourceMap::end() {
    return map.end();
}

NonZeroResourceMap::NonZeroResourceMapConstIterator NonZeroResourceMap::begin() const {
    return map.begin();
}

NonZeroResourceMap::NonZeroResourceMapConstIterator NonZeroResourceMap::end() const {
    return map.end();
}
