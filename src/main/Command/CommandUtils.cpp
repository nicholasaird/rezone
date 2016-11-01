#include "CommandUtils.h"

CommandArguments CommandUtils::fromDocopt(std::map<std::string, docopt::value> docoptArgs) {
    CommandArguments commandArgs;

    for(const auto& pair : docoptArgs) {
        std::string arg = pair.first;
        docopt::value docoptVal = pair.second;

        if(docoptVal.isBool()) {
            commandArgs.add(arg, docoptVal.asBool() ? "true" : "false");
        }
        else if(docoptVal.isString()) {
            commandArgs.add(arg, docoptVal.asString());
        }
        else if(docoptVal.isLong()) {
            commandArgs.add(arg, std::to_string(docoptVal.asLong()));
        }
        else if(docoptVal.isStringList()) {
            std::vector<std::string> stringList = docoptVal.asStringList();

            std::string val;
            for(int i = 0; i < stringList.size(); i++) {
                if(i > 0) {
                    val = val + " " + stringList.at(i);
                }
                else {
                    val = val + stringList.at(i);
                }
            }

            commandArgs.add(arg, val);
        }
    }
}
