#include "ResourceException.h"

ResourceException::ResourceException(const std::string& message)
    : runtime_error(message)
{
    //
}
