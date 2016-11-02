#include "Command.h"

void Command::execute(std::vector<std::string> words) {
    try {
        executeThrows(words);
    }
    catch (docopt::DocoptExitHelp e) {
        std::cout << getUsage() << std::endl;
    }
    catch (docopt::DocoptArgumentError e) {
        std::cout << e.what() << std::endl;
        std::cout << "Type --help for usage." << std::endl;
    }
    catch (std::runtime_error e) {
        std::cout << "Some error occurred" << std::endl;
    }
}

void Command::executeThrows(std::vector<std::string> words) {
    std::map<std::string, docopt::value> docoptArgs = docopt::docopt_parse(getUsage(), words, true);
    CommandArguments commandArgs = CommandUtils::fromDocopt(docoptArgs);

    execute(commandArgs);
}

void Command::execute(CommandArguments& commandArgs) {
    try {
        executeThrows(commandArgs);
    }
    catch (UnfoundArgumentException e) {
        std::cout << e.what() << std::endl;

        return;
    }
}
