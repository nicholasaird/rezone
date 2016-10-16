#include "ResourceCount.hpp"

ResourceCount::ResourceCount()
    : counts()
{
    //
}

ResourceCount::ResourceCount(std::map<Resource, int> counts)
    : counts(counts)
{
    filterOutLessOrEqualToZero();
}

ResourceCount::~ResourceCount() {
    //
}

void ResourceCount::filterOutLessOrEqualToZero() {
    for(auto pair : counts) {
        Resource resource = pair.first;
        int count = pair.second;

        if(count <= 0){
            counts.erase(resource);
        }
    }
}

bool ResourceCount::operator==(const ResourceCount& rhs) const {
    return this->counts == rhs.counts;
}

bool ResourceCount::operator!=(const ResourceCount& rhs) const {
    return !(*this == rhs);
}

ResourceCount ResourceCount::operator-(const ResourceCount& rhs) const {
    std::map<Resource, int> newCounts(counts);

    for(auto pair : rhs) {
        Resource rhsResource = pair.first;
        int rhsCount = pair.second;

        if(newCounts.count(rhsResource) > 0) {
            newCounts[rhsResource] = newCounts[rhsResource] - rhsCount;
        }
        else {
            newCounts[rhsResource] = -rhsCount;
        }
    }

    ResourceCount newCount(newCounts);
    return newCount;
}

std::ostream& operator<<(std::ostream& stream, const ResourceCount& count) {
    stream << "{";
    for(auto pair : count.counts) {
        stream << "{" << pair.first << ", " << pair.second << "}";
    }
    stream << "}";
    return stream;
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
