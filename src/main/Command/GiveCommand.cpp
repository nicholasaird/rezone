#include "GiveCommand.h"

GiveCommand::GiveCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection)
    : MapCommand(map)
    , selection(selection)
{
    //
}

void GiveCommand::execute(CommandArguments& commandArgs) {
    try {
        executeThrows(commandArgs);
    }
    catch (UnfoundArgumentException e) {
        std::cout << e.what() << std::endl;

        return;
    }
}

void GiveCommand::executeThrows(CommandArguments& commandArgs) {
    bool all = commandArgs.getBool("--all");

    if(all) {
        for(const auto& coord : selection->getSelectedSet()) {
            std::shared_ptr<Zone> zone = map->getZone(coord);
            Stock unprovided = zone->getUnprovided();
            zone->provide(unprovided);

            std::cout << "Cell " << coord << ", gave " << unprovided << std::endl;
        }
    }
    else{
        std::cout << "Unimplemented" << std::endl;
    }
}

std::string GiveCommand::getUsage() {
    return usage;
}
