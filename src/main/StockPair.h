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

    bool operator==(const StockPair& rhs) const {
        return input == rhs.input && output == rhs.output;
    }

    bool operator !=(const StockPair& rhs) const {
        return !(*this == rhs);
    }

    bool subsetOf(const StockPair& rhs) const {
        return this->input.subsetOf(rhs.input) && this->output.subsetOf(rhs.output);
    }

    bool supersetOf(const StockPair& rhs) const {
        return rhs.subsetOf(*this);
    }
};

#endif
