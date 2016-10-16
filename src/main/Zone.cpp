#include "Zone.h"

Zone::Zone()
    : level(0)
    , connectedToElectricity(false)
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

bool Zone::isConnectedTo(Utility utility) {
    switch(utility) {
        case Utility::ELECTRICITY:
            return connectedToElectricity;
        default:
            return false;
    }
}

void Zone::setConnectedTo(Utility utility, bool connected) {
    switch(utility) {
        case Utility::ELECTRICITY:
            connectedToElectricity = connected;
        default:
            break;
    }
}

void Zone::updateLevel() {
    // If needs are met
        // Update level and get new input / output counts
    // Otherwise, if needs aren't met
        // Downgrade to highest level that has needs met
    if(connectedToElectricity) {
        setLevel(level+1);
    }
}

int Zone::getLevel() {
    return level;
}

void Zone::setLevel(int level) {
    this->level = level;
    productionTotal.set(Resource::PERSON, level);
}
