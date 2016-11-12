#include "CommandArguments.h"

#include <iostream>

CommandArguments::CommandArguments()
    : args()
{
    //
}

void CommandArguments::add(std::string arg, int val){
    args[arg] = std::to_string(val);
}

void CommandArguments::add(std::string arg, std::string val){
    args[arg] = val;
}

int CommandArguments::getInt(std::string arg){
    std::string valStr = get(arg);
    int valInt;

    try{
        valInt = std::stoi(valStr);
    }
    catch(std::invalid_argument e) {
        throw WrongTypeArgumentException("Could not convert arg {" + arg + ": " + valStr + "} to an int");
    }

    return valInt;
}

bool CommandArguments::getBool(std::string arg) {
    std::string val = get(arg);

    if(val == "true") {
        return true;
    }
    else if(val == "false") {
        return false;
    }
    else {
        throw WrongTypeArgumentException("Could not convert arg {" + arg + ": " + val + "} to a bool");
    }
}

std::string CommandArguments::getString(std::string arg){
    return get(arg);
}

std::string CommandArguments::get(std::string arg){
    if(args.count(arg) < 1) {
        throw UnfoundArgumentException(arg);
    }

    return args[arg];
}
