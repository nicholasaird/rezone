#ifndef RESOURCECOUNT_HPP
#define RESOURCECOUNT_HPP

#include <iostream>  // std::ostream
#include <map>
#include <utility>

#include "Resource.hpp"

class ResourceCount {
private:
    std::map<Resource, int> counts;
public:
    typedef std::map<Resource, int>::iterator ResourceCountIterator;
    typedef std::map<Resource, int>::const_iterator ResourceCountConstIterator;

private:
    void filterOutLessOrEqualToZero();
public:
    ResourceCount();
    ResourceCount(std::map<Resource, int> counts);
    virtual ~ResourceCount();

    bool operator==(const ResourceCount& rhs) const;
    bool operator!=(const ResourceCount& rhs) const;
    ResourceCount operator-(const ResourceCount& rhs) const;
    // friend std::ostream& operator<<(std::ostream& stream, const ResourceCount& count);
    friend std::ostream& operator<<(std::ostream& os, ResourceCount const& v);

    void set(Resource resource, int count);
    int get(Resource resource);
    ResourceCountIterator begin();
    ResourceCountIterator end();
    ResourceCountConstIterator begin() const;
    ResourceCountConstIterator end() const;
};

#endif
