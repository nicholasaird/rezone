#ifndef NEEDS_HPP
#define NEEDS_HPP

#include "StockPair.h"

class Needs {
public:
    virtual StockPair required(int level) = 0;
    virtual StockPair max(int level) = 0;
    virtual StockPair downgradeThreshold(int level) = 0;
};

#endif
