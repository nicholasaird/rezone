#ifndef CAP_HPP
#define CAP_HPP

#include "Stock.h"
#include "StockPair.h"

class Cap {
private:
    StockPair recipe;
public:
    Cap(StockPair recipe);
    void update(Stock relief);
    Stock getInput();
    Stock getOutput();
};

#endif
