#ifndef RESOURCECOUNT_HPP
#define RESOURCECOUNT_HPP

#include <map>
#include <utility>

#include "Resource.hpp"

class ResourceCount {
public:
    typedef std::map<Resource, int>::iterator ResourceCountIterator;
    typedef std::map<Resource, int>::const_iterator ResourceCountConstIterator;
private:
    std::map<Resource, int> counts;
public:
    ResourceCount();
    virtual ~ResourceCount();
    bool operator==(const ResourceCount& rhs) const;
    bool operator!=(const ResourceCount& rhs) const;
    void set(Resource resource, int count);
    int get(Resource resource);
    ResourceCountIterator begin();
    ResourceCountIterator end();
    ResourceCountConstIterator begin() const;
    ResourceCountConstIterator end() const;
};

#endif
