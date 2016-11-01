#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <string>

#include "CommandArguments.h"
#include "CommandUtils.h"
#include "docopt.h"

class Command {
public:
    void execute(std::vector<std::string> words);
    virtual void execute(CommandArguments& args) = 0;
    virtual std::string getUsage() = 0;
};

#endif
