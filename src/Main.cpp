#include <iostream>
#include <memory>  // shared pointer
#include <string>

#include "main/Map.h"
#include "main/MapSelection.h"
#include "main/Command/CommandPrompt.h"
#include "main/Command/SelectCommand.h"
#include "main/Command/UnselectCommand.h"
#include "main/Command/QuitCommand.h"

void run();
void loop();

std::shared_ptr<bool> running = std::make_shared<bool>(true);
std::shared_ptr<Map> map;
std::shared_ptr<MapSelection> mapSelection;
Stock relief;

int main(int argc, char* argv[]) {
    run();

    return 0;
}

void run() {
    map = std::make_shared<Map>(4, 4);
    mapSelection = std::make_shared<MapSelection>();
    relief = Stock({{Resource::PERSON, 10}});

    loop();
}

void loop() {
    CommandPrompt commandPrompt;
    commandPrompt.addCommand("select", std::make_shared<SelectCommand>(map, mapSelection));
    commandPrompt.addCommand("unselect", std::make_shared<UnselectCommand>(map, mapSelection));
    commandPrompt.addCommand("q", std::make_shared<QuitCommand>(running));
    commandPrompt.addCommand("quit", std::make_shared<QuitCommand>(running));

    while(*running) {
        commandPrompt.prompt();
    }
}
