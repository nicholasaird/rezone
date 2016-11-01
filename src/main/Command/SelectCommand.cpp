#include "SelectCommand.h"

SelectCommand::SelectCommand(std::shared_ptr<Map> map, std::shared_ptr<MapSelection> selection)
    : MapCommand(map)
    , selection(selection)
{
    //
}

void SelectCommand::execute(CommandArguments& args) {
    int x = args.getInt("x");
    int y = args.getInt("y");

    selection->add(x, y);
}
