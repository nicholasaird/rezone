#ifndef LEVELER_HPP
#define LEVELER_HPP

#include<memory>  // shared_ptr

#include "Needs.h"
#include "StockPair.h"

class Leveler {
private:
    int level;
    StockPair metStockPair;
    std::shared_ptr<Needs> needs;
public:
    Leveler(std::shared_ptr<Needs> needs);
    void update();
    int getLevel();
};

#endif
