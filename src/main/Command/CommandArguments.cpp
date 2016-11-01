#include "CommandArguments.h"

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

std::string CommandArguments::getString(std::string arg){
    return get(arg);
}

std::string CommandArguments::get(std::string arg){
    if(args.count(arg) < 1) {
        throw UnfoundArgumentException(arg);
    }

    return args[arg];
}
