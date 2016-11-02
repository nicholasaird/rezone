#include "QuitCommand.h"

QuitCommand::QuitCommand(std::shared_ptr<bool> running)
    : running(running)
{
    //
}

void QuitCommand::executeThrows(CommandArguments& commandArgs) {
    *running = false;
}

std::string QuitCommand::getUsage() {
    return usage;
}
