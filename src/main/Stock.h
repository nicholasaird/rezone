#ifndef STOCK_HPP
#define STOCK_HPP

#include <algorithm>  // min, min_element
#include <iostream>  // ostream
#include <limits>  //numeric_limits
#include <map>
#include <utility>

#include "Resource.h"
#include "NonZeroResourceMap.h"

class Stock {
private:
    NonZeroResourceMap map;
public:
    typedef NonZeroResourceMap::const_iterator const_iterator;

private:
public:
    Stock();
    Stock(std::map<Resource, int> counts);
    Stock(NonZeroResourceMap map);
    virtual ~Stock();

    bool operator==(const Stock& rhs) const;
    bool operator!=(const Stock& rhs) const;
    Stock operator-() const;
    Stock& operator*=(const int& mult);
    Stock& operator/=(const int& mult);
    Stock& operator-=(const Stock& rhs);
    Stock& operator+=(const Stock& rhs);
    Stock operator*(const int& mult) const;
    Stock operator/(const int& div) const;
    Stock operator-(const Stock& rhs) const;
    Stock operator+(const Stock& rhs) const;
    bool subsetOf(const Stock& rhs) const;
    bool supersetOf(const Stock& rhs) const;
    int sum() const;
    friend std::ostream& operator<<(std::ostream& stream, const Stock& count);

    void set(Resource resource, int count);
    int get(Resource resource);
    const_iterator begin() const;
    const_iterator end() const;
    int timesItContains(const Stock& other) const;
};

#endif
