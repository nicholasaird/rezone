#include "Stock.h"

Stock::Stock()
    : counts()
{
    //
}

Stock::Stock(std::map<Resource, int> counts)
    : counts(counts)
{
    filterOutLessOrEqualToZero();
}

Stock::~Stock() {
    //
}

void Stock::filterOutLessOrEqualToZero() {
    for(auto pair : counts) {
        Resource resource = pair.first;
        int count = pair.second;

        if(count <= 0){
            counts.erase(resource);
        }
    }
}

bool Stock::operator==(const Stock& rhs) const {
    return this->counts == rhs.counts;
}

bool Stock::operator!=(const Stock& rhs) const {
    return !(*this == rhs);
}

Stock Stock::operator-(const Stock& rhs) const {
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

    Stock newCount(newCounts);
    return newCount;
}

bool Stock::subsetOf(const Stock& rhs) const {
    std::map<Resource, int> otherCounts = rhs.counts;

    for(auto pair : counts) {
        Resource resource = pair.first;
        int count = pair.second;

        if(otherCounts.count(resource) < 1) {
            return false;
        }
        else if (otherCounts[resource] != count) {
            return false;
        }
    }

    return true;
}

bool Stock::supersetOf(const Stock& rhs) const {
    return rhs.subsetOf(*this);
}

std::ostream& operator<<(std::ostream& stream, const Stock& count) {
    stream << "{";
    for(auto pair : count.counts) {
        stream << "{" << pair.first << ", " << pair.second << "}";
    }
    stream << "}";
    return stream;
}

void Stock::set(Resource resource, int count) {
    counts[resource] = count;
}

int Stock::get(Resource resource) {
    if(counts.count(resource) > 0) {
        return counts[resource];
    }
    else {
        return 0;
    }
}

Stock::StockIterator Stock::begin() {
    return counts.begin();
}

Stock::StockIterator Stock::end() {
    return counts.end();
}

Stock::StockConstIterator Stock::begin() const {
    return counts.begin();
}

Stock::StockConstIterator Stock::end() const {
    return counts.end();
}
