#ifndef UNSELECTCOMMAND_HPP
#define UNSELECTCOMMAND_HPP

#include <memory> // shared pointer

#include "CommandArguments.h"
#include "Coord2.h"
#include "MapCommand.h"
#include "MapSelection.h"
#include "Map.h"
#include "Utils.h"

class UnselectCommand : public MapCommand {
private:
    std::shared_ptr<MapSelection> selection;
    const std::string usage =
R"(Usage:
    unselect <x> <y>
    unselect --all

Options:
    -a --all  Choose all zones
)";

public:
    UnselectCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection);
    void executeThrows(CommandArguments& args) override;
    std::string getUsage() override;
};

#endif
