#include "WrongTypeArgumentException.h"

WrongTypeArgumentException::WrongTypeArgumentException(const std::string& message)
    : runtime_error(message)
{
    //
}
