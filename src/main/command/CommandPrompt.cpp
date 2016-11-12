#include "CommandPrompt.h"

void CommandPrompt::addCommand(std::string name, std::shared_ptr<Command> command) {
    commandMapping[name] = command;
}

void CommandPrompt::prompt() {
    std::string input;
    std::cout << "> ";
    getline(std::cin, input);

    std::vector<std::string> tokens = StringUtils::words(input);

    if(tokens.size() > 0) {
        std::string commandName = tokens.at(0);

        if(commandMapping.count(commandName) > 0) {
            std::vector<std::string> tailArgs = VectorUtils::getTail(tokens);
            commandMapping[commandName]->execute(tailArgs);
        }
        else {
            // Unknown command name
            std::cout << "Unknown command" << std::endl;
        }
    }
    else {
        // No command, so skip
    }
}
