#ifndef COMMANDARGUMENTS_HPP
#define COMMANDARGUMENTS_HPP

#include <map>
#include <string>

#include "UnfoundArgumentException.h"
#include "WrongTypeArgumentException.h"

class CommandArguments {
private:
    std::map<std::string, std::string> args;

public:
    CommandArguments();
    void add(std::string arg, int val);
    void add(std::string arg, std::string val);
    int getInt(std::string arg);
    std::string getString(std::string arg);
private:
    std::string get(std::string arg);
};

#endif
