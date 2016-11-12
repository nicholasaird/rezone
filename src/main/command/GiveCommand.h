#ifndef GIVECOMMAND_HPP
#define GIVECOMMAND_HPP

#include <memory>  // shared_ptr
#include <string>

#include "CommandArguments.h"
#include "Map.h"
#include "MapCommand.h"
#include "MapSelection.h"

class GiveCommand : public MapCommand {
private:
    std::string usage =
R"(Usage:
    give (<resource> <amount>)...
    give --all

Options:
    -a --all  Give all needed resources

Resources:
    COM_PRODUCT
    ELECTRICITY
    IND_PRODUCT
    PERSON
)";
    std::shared_ptr<MapSelection> selection;

public:
    GiveCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection);
    void executeThrows(CommandArguments& commandArgs) override;
    std::string getUsage() override;
};

#endif
