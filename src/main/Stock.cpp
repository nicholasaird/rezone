#include "Stock.h"

#include <algorithm>  // min, min_element
#include <limits>  //numeric_limits

Stock::Stock()
    : map()
{
    //
}

Stock::Stock(std::map<Resource, int> counts)
    : map(counts)
{
    //
}

Stock::Stock(NonZeroResourceMap map)
    : map(map)
{
    //
}

Stock::~Stock() {
    //
}

bool Stock::operator==(const Stock& rhs) const {
    return map == rhs.map;
}

bool Stock::operator!=(const Stock& rhs) const {
    return !(*this == rhs);
}

Stock Stock::operator-() const {
    NonZeroResourceMap newMap(map);
    for(const auto& pair : newMap) {
        newMap.set(pair.first, -pair.second);
    }

    return Stock(newMap);
}

Stock& Stock::operator-=(const Stock& rhs) {
    return *this += -rhs;
}

Stock& Stock::operator+=(const Stock& rhs) {
    for(const auto& pair : rhs.map) {
        map.set(pair.first, map.get(pair.first) + pair.second);
    }

    return *this;
}

Stock& Stock::operator*=(const int& mult) {
    for(const auto& pair : map) {
        map.set(pair.first, map.get(pair.first) * mult);
    }

    return *this;
}

Stock& Stock::operator/=(const int& div) {
    for(const auto& pair : map) {
        map.set(pair.first, map.get(pair.first) / div);
    }

    return *this;
}

Stock Stock::operator*(const int& mult) const {
    Stock newStock(map);

    return newStock *= mult;
}

Stock Stock::operator/(const int& div) const {
    Stock newStock(map);

    return newStock /= div;
}

Stock Stock::operator-(const Stock& rhs) const {
    NonZeroResourceMap newMap(map);

    for(const auto& pair : rhs.map) {
        newMap.set(pair.first, map.get(pair.first) - pair.second);
    }

    return Stock(newMap);
}

Stock Stock::operator+(const Stock& rhs) const {
    NonZeroResourceMap newMap(map);

    for(const auto& pair : rhs.map) {
        newMap.set(pair.first, newMap.get(pair.first) + pair.second);
    }

    return Stock(newMap);
}

bool Stock::subsetOf(const Stock& rhs) const {
    for(const auto& pair : map) {
        if(map.get(pair.first) > rhs.map.get(pair.first)) {
            return false;
        }
    }

    return true;
}

bool Stock::supersetOf(const Stock& rhs) const {
    for(const auto& pair : rhs.map) {
        if(rhs.map.get(pair.first) > map.get(pair.first)) {
            return false;
        }
    }

    return true;
}

int Stock::sum() const {
    int sum = 0;

    for(const auto& pair : map) {
        sum += pair.second;
    }

    return sum;
}

std::ostream& operator<<(std::ostream& stream, const Stock& stock) {
    stream << "{";
    for(const auto& pair : stock.map) {
        stream << "{" << pair.first << ", " << pair.second << "}";
    }
    stream << "}";
    return stream;
}

void Stock::set(Resource resource, int val) {
    map.set(resource, val);
}

int Stock::get(Resource resource) {
    return map.get(resource);
}

Stock::const_iterator Stock::begin() const {
    return map.begin();
}

Stock::const_iterator Stock::end() const {
    return map.end();
}

int Stock::timesItContains(const Stock& other) const {
    if(*this == Stock()) {
        return 0;
    }

    int minTimesContained = std::numeric_limits<int>::max();

    for(const auto& pair : other.map) {
        int otherCount = pair.second;
        int count = map.get(pair.first);

        minTimesContained = std::min(minTimesContained, count / otherCount);
    }

    return minTimesContained;
}
