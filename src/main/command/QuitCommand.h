#ifndef QUITCOMMAND_HPP
#define QUITCOMMAND_HPP

#include <memory>  // shared_ptr
#include <string>

#include "command/Command.h"

class QuitCommand : public Command {
private:
    std::string usage = "Usage: quit";
    std::shared_ptr<bool> running;
public:
    QuitCommand(std::shared_ptr<bool> running);
    void executeThrows(CommandArguments& commandArgs) override;
    std::string getUsage() override;
};

#endif
