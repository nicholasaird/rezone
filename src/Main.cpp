#include <iomanip>
#include <memory>

#include "main/Grid.h"
#include "main/Zone.h"

void resetZones(Grid<std::shared_ptr<Zone> >& zones);
void printZones(Grid<std::shared_ptr<Zone> >& zones);

int main() {
    Grid<std::shared_ptr<Zone> > zones(4, 4);

    resetZones(zones);

    printZones(zones);

    return 0;
}

void resetZones(Grid<std::shared_ptr<Zone> >& zones) {
    for(int x = 0; x < zones.getWidth(); x++) {
        for(int y = 0; y < zones.getHeight(); y++) {
            zones(x, y) = std::make_shared<Zone>("Empty", StockPair(Stock(), Stock()));
        }
    }
}

void printZones(Grid<std::shared_ptr<Zone> >& zones) {
    for(int x = 0; x < zones.getWidth(); x++) {
        std::cout << "+------------";
    }

    std::cout << "+" << std::endl;

    for(int x = 0; x < zones.getWidth(); x++) {

        for(int y = 0; y < zones.getHeight(); y++) {
            std::cout << "| ";

            Zone& zone = *zones(x, y);
            std::string nameAbbreviation = zone.getName().substr(0, 3);
            Stock production = zone.getTaken();
            int takeAmount = production.sum();
            std::cout << nameAbbreviation << ": " << std::right << std::setw(5) << std::to_string(takeAmount);
            std::cout << " ";
        }

        std::cout << "|" << std::endl;

        for(int x = 0; x < zones.getWidth(); x++) {
            std::cout << "+------------";
        }
        std::cout << "+" << std::endl;
    }
}
