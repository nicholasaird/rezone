#ifndef COMMANDPROMPT_HPP
#define COMMANDPROMPT_HPP

#include <map>
#include <memory>  // shared pointer
#include <string>
#include <vector>

#include "Command.h"
#include "Utils.h"

class CommandPrompt {
private:
    std::map<std::string, std::shared_ptr<Command> > commandMapping;

public:
    void addCommand(std::string name, std::shared_ptr<Command> command);
    void prompt();
};

#endif
