#ifndef CAP_HPP
#define CAP_HPP

#include "Stock.h"
#include "StockPair.h"

class Cap {
public:
    Cap(StockPair recipe);
    void update(Stock relief);
    Stock getInput();
    Stock getOutput();
};

#endif
