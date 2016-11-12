#include <iostream>
#include <memory>  // shared pointer
#include <string>

#include "main/Map.h"
#include "main/MapSelection.h"
#include "main/command/CommandPrompt.h"
#include "main/command/GiveCommand.h"
#include "main/command/SelectCommand.h"
#include "main/command/UnselectCommand.h"
#include "main/command/QuitCommand.h"

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

    commandPrompt.addCommand("s", std::make_shared<SelectCommand>(map, mapSelection));
    commandPrompt.addCommand("select", std::make_shared<SelectCommand>(map, mapSelection));

    commandPrompt.addCommand("u", std::make_shared<UnselectCommand>(map, mapSelection));
    commandPrompt.addCommand("unselect", std::make_shared<UnselectCommand>(map, mapSelection));

    commandPrompt.addCommand("g", std::make_shared<GiveCommand>(map, mapSelection));
    commandPrompt.addCommand("give", std::make_shared<GiveCommand>(map, mapSelection));

    commandPrompt.addCommand("q", std::make_shared<QuitCommand>(running));
    commandPrompt.addCommand("quit", std::make_shared<QuitCommand>(running));

    while(*running) {
        commandPrompt.prompt();
    }
}
