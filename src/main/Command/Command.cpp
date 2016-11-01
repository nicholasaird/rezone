#include "Command.h"

void Command::execute(std::vector<std::string> words) {
    std::map<std::string, docopt::value> docoptArgs;
    try {
        docoptArgs = docopt::docopt_parse(getUsage(), words, false);
    }
    catch (std::runtime_error e) {
        std::cout << "Runtime exception in Command::execute(words): " << e.what() << std::endl;
        std::cout << getUsage() << std::endl;

        return;
    }

    CommandArguments commandArgs = CommandUtils::fromDocopt(docoptArgs);

    execute(commandArgs);
}
