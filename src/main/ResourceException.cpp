#include "ResourceException.h"

ResourceException::ResourceException()
    : runtime_error("")
{
    //
}

ResourceException::ResourceException(const std::string& message)
    : runtime_error(message)
{
    //
}
