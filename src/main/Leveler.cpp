#include "Leveler.h"

Leveler::Leveler(std::shared_ptr<Needs> needs)
    : level(0)
    , metStockPair()
    , needs(needs)
{
    //
}

void Leveler::update() {
    StockPair required = needs->required(level);
    bool meetsNeedsForLevelUp = metStockPair.supersetOf(required);
    if(meetsNeedsForLevelUp) {
        level++;
    }
}

int Leveler::getLevel() {
    return level;
}
