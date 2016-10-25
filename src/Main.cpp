#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>  // istringstream
#include <iterator>  // istream_iterator

#include "main/Grid.h"
#include "main/Zone.h"

void resetZones(Grid<std::shared_ptr<Zone> >& zones);
void printZones(Grid<std::shared_ptr<Zone> >& zones);
void run();
void loop(Grid<std::shared_ptr<Zone> >& zones, Stock& relief);
std::string getCommand();
void executeCommand(std::string command);
void updateZones(Grid<std::shared_ptr<Zone> >& zones, Stock& relief);

bool running = true;

int main() {
    run();

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
    std::cout << "Map" << std::endl;

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

void run() {
    Grid<std::shared_ptr<Zone> > zones(4, 4);
    resetZones(zones);

    Stock relief({{Resource::PERSON, 10}});

    loop(zones, relief);
}

void loop(Grid<std::shared_ptr<Zone> >& zones, Stock& relief) {
    while(running) {
        printZones(zones);
        std::cout << std::endl;

        std::string command = getCommand();

        executeCommand(command);

        updateZones(zones, relief);
    }
}

std::string getCommand() {
    std::string command;
    std::cout << "> ";
    getline(std::cin, command);

    return command;
}

void executeCommand(std::string command) {
    std::istringstream iss(command);
    std::istream_iterator<std::string> beg(iss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> tokens(beg, end);

    if(tokens.size() == 0) {
        return;
    }

    if(tokens[0] == "q") {
        std::cout << "quit" << std::endl;
        running = false;
    }
}

void updateZones(Grid<std::shared_ptr<Zone> >& zones, Stock& relief) {
    for(int x = 0; x < zones.getWidth(); x++) {
        for(int y = 0; y < zones.getHeight(); y++) {
            Zone& zone = *zones(x, y);
            zone.updateCap(relief);
            zone.updateProduction();
        }
    }
}
