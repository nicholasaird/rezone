#include "Zone.h"

Zone::Zone()
{
    //
}

Zone::~Zone() {
    //
}

Stock Zone::getProductionTotal() {
    return productionTotal;
}

Stock Zone::getProductionUnused() {
    return productionTotal - productionUsed;
}
