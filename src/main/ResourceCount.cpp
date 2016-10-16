#include "ResourceCount.hpp"

ResourceCount::ResourceCount()
    : counts()
{
    //
}

ResourceCount::~ResourceCount() {
    //
}

bool ResourceCount::operator==(const ResourceCount& rhs) const {
    return this->counts == rhs.counts;
}

bool ResourceCount::operator!=(const ResourceCount& rhs) const {
    return !(*this == rhs);
}

void ResourceCount::set(Resource resource, int count) {
    counts[resource] = count;
}

int ResourceCount::get(Resource resource) {
    if(counts.count(resource) > 0) {
        return counts[resource];
    }
    else {
        return 0;
    }
}

ResourceCount::ResourceCountIterator ResourceCount::begin() {
    return counts.begin();
}

ResourceCount::ResourceCountIterator ResourceCount::end() {
    return counts.end();
}

ResourceCount::ResourceCountConstIterator ResourceCount::begin() const {
    return counts.begin();
}

ResourceCount::ResourceCountConstIterator ResourceCount::end() const {
    return counts.end();
}
