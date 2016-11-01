#include "QuitCommand.h"

QuitCommand::QuitCommand(std::shared_ptr<bool> running)
    : running(running)
{
    //
}

void QuitCommand::execute(CommandArguments& commandArgs) {
    *running = false;
}

std::string QuitCommand::getUsage() {
    return usage;
}
