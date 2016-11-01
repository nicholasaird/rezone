#ifndef SELECTCOMMAND_HPP
#define SELECTCOMMAND_HPP

#include <memory> // shared pointer

#include "CommandArguments.h"
#include "MapCommand.h"
#include "MapSelection.h"
#include "Map.h"

class SelectCommand : public MapCommand {
private:
    std::shared_ptr<MapSelection> selection;

public:
    SelectCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection);
    void execute(CommandArguments& args) override;
};

#endif
