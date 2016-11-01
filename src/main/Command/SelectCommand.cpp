#include "SelectCommand.h"

SelectCommand::SelectCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection)
    : MapCommand(map)
    , selection(selection)
{
    //
}

void SelectCommand::execute(CommandArguments& args) {
    try {
        executeThrows(args);
    }
    catch (UnfoundArgumentException e) {
        std::cout << e.what() << std::endl;

        return;
    }
}

void SelectCommand::executeThrows(CommandArguments& args) {
    bool selectAll = args.getBool("--all");

    if(selectAll) {
        std::cout << "Unimplemented" << std::endl;
    }
    else{
        int x = args.getInt("<x>");
        int y = args.getInt("<y>");

        selection->add(x, y);
    }
}

std::string SelectCommand::getUsage() {
    return usage;
}
