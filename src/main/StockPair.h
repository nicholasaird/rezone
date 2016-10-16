#ifndef STOCKPAIR_HPP
#define STOCKPAIR_HPP

#include "Stock.h"

class StockPair {
public:
    Stock input;
    Stock output;

    StockPair()
        : input()
        , output()
    {
        //
    }

    StockPair(Stock input, Stock output)
        : input(input)
        , output(output)
    {
        //
    }

    bool operator<(const StockPair& rhs) const {
        return (input < rhs.input && output < rhs.output);
    }
};

#endif
