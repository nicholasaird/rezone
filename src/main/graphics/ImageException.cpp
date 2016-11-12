#include "ImageException.h"

ImageException::ImageException(const std::string& message)
    : std::runtime_error(message)
{

}
