#include "SelectCommand.h"

SelectCommand::SelectCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection)
    : MapCommand(map)
    , selection(selection)
{
    //
}

void SelectCommand::executeThrows(CommandArguments& args) {
    bool selectAll = args.getBool("--all");

    if(selectAll) {
        for(int x = 0; x < map->getWidth(); x++) {
            for(int y = 0; y < map->getWidth(); y++) {
                selection->add(Coord2(x, y));
            }
        }
    }
    else{
        int x = args.getInt("<x>");
        int y = args.getInt("<y>");

        selection->add(Coord2(x, y));
    }

    std::cout << "Selection:" << std::endl;
    std::cout << selection->getSelectedSet();
}

std::string SelectCommand::getUsage() {
    return usage;
}
