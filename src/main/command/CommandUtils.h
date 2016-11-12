#ifndef COMMANDUTILS_HPP
#define COMMANDUTILS_HPP

#include <map>
#include <string>
#include <vector>

#include "CommandArguments.h"
#include "docopt.h"

namespace CommandUtils {
    CommandArguments fromDocopt(std::map<std::string, docopt::value> docoptArgs);
}

#endif
