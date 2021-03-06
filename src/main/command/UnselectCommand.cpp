#include "UnselectCommand.h"

UnselectCommand::UnselectCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection)
    : MapCommand(map)
    , selection(selection)
{
    //
}

void UnselectCommand::executeThrows(CommandArguments& args) {
    bool selectAll = args.getBool("--all");

    if(selectAll) {
        selection->clear();
    }
    else{
        int x = args.getInt("<x>");
        int y = args.getInt("<y>");

        selection->remove(Coord2(x, y));
    }

    std::cout << "Selection:" << std::endl;
    std::cout << selection->getSelectedSet();
}

std::string UnselectCommand::getUsage() {
    return usage;
}
