#include "UnfoundArgumentException.h"

UnfoundArgumentException::UnfoundArgumentException(const std::string& argumentName)
    : runtime_error("Unfound argument: " + argumentName)
{
    //
}
