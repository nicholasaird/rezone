#include <iomanip>
#include <memory>

#include "main/Grid.h"
#include "main/Zone.h"

int main() {
    int width = 4;
    int height = 4;
    Grid<std::shared_ptr<Zone> > zones(width, height);

    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            zones(x, y) = std::make_shared<Zone>("Empty", StockPair(Stock(), Stock()));
        }
    }

    for(int x = 0; x < width; x++) {
        std::cout << "+------------";
    }

    std::cout << "+" << std::endl;

    for(int x = 0; x < width; x++) {

        for(int y = 0; y < height; y++) {
            std::cout << "| ";

            Zone& zone = *zones(x, y);
            std::string nameAbbreviation = zone.getName().substr(0, 3);
            Stock production = zone.getTaken();
            int takeAmount = production.sum();
            std::cout << nameAbbreviation << ": " << std::right << std::setw(5) << std::to_string(takeAmount);
            std::cout << " ";
        }

        std::cout << "|" << std::endl;

        for(int x = 0; x < width; x++) {
            std::cout << "+------------";
        }
        std::cout << "+" << std::endl;
    }

    return 0;
}
