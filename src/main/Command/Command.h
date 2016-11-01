#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <map>

#include "CommandArguments.h"

class Command {
public:
    virtual void execute(CommandArguments& args) = 0;
};

#endif
