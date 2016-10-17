#ifndef STOCK_HPP
#define STOCK_HPP

#include <iostream>  // std::ostream
#include <map>
#include <utility>

#include "Resource.h"

class Stock {
private:
    std::map<Resource, int> counts;
public:
    typedef std::map<Resource, int>::iterator StockIterator;
    typedef std::map<Resource, int>::const_iterator StockConstIterator;

private:
    void removeZeros();
public:
    Stock();
    Stock(std::map<Resource, int> counts);
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
    friend std::ostream& operator<<(std::ostream& stream, const Stock& count);

    void set(Resource resource, int count);
    int get(Resource resource);
    StockIterator begin();
    StockIterator end();
    StockConstIterator begin() const;
    StockConstIterator end() const;
};

#endif
