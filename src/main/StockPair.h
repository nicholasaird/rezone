#ifndef STOCKPAIR_HPP
#define STOCKPAIR_HPP

#include "Stock.h"

struct StockPair {
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
};

#endif
