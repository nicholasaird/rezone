#ifndef QUOTA_HPP
#define QUOTA_HPP

#include "Stock.h"

class Quota {
private:
    Stock total;
    Stock met;
public:
    Quota();
    Quota(Stock total);
    Quota(Stock total, Stock met);
    Stock getTotal();
    Stock getMet();
    Stock getUnmet();
    void setTotal(Stock total);
    void setMet(Stock met);
    void setUnmet(Stock unmet);
};

#endif
