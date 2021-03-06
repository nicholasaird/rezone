#ifndef SELECTCOMMAND_HPP
#define SELECTCOMMAND_HPP

#include <memory> // shared pointer

#include "CommandArguments.h"
#include "MapCommand.h"
#include "MapSelection.h"
#include "Map.h"
#include "math/Coord2.h"
#include "Utils.h"

class SelectCommand : public MapCommand {
private:
    std::shared_ptr<MapSelection> selection;
    const std::string usage =
R"(Usage:
    select <x> <y>
    select --all

Options:
    -a --all  Choose all zones
)";

public:
    SelectCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection);
    void executeThrows(CommandArguments& args) override;
    std::string getUsage() override;
};

#endif
