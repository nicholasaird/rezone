#include "Quota.hpp"

Quota::Quota()
    : total()
    , met()
{
    //
}

Quota::Quota(Stock total)
    : total(total)
    , met()
{
    //
}

Quota::Quota(Stock total, Stock met)
    : total(total)
    , met(met)
{
    //
}

Stock Quota::getTotal() {
    return total;
}

Stock Quota::getMet() {
    return met;
}

Stock Quota::getUnmet() {
    return total - met;
}

void Quota::setTotal(Stock total) {
    this->total = total;
}

void Quota::setMet(Stock met) {
    this->met = met;
}

void Quota::setUnmet(Stock unmet) {
    this->met = total - unmet;
}
