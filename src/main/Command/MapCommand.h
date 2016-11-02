#ifndef MAPCOMMAND_HPP
#define MAPCOMMAND_HPP

#include <memory> // shared pointer

#include "Command.h"
#include "Map.h"

class MapCommand : public Command {
protected:
    std::shared_ptr<Map> map;

public:
    MapCommand(std::shared_ptr<Map> map);
};

#endif
