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
    virtual ~Command();
    void execute(std::vector<std::string> words);
    void executeThrows(std::vector<std::string> words);
    void execute(CommandArguments& commandArgs);
    virtual void executeThrows(CommandArguments& commandArgs) = 0;
    virtual std::string getUsage() = 0;
};

#endif
