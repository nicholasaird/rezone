#include "DimException.h"

#include <string>

DimException::DimException(int x, int y, std::string message)
    : runtime_error(
        "Dim2(" + std::to_string(x) + "," + std::to_string(y) + "): " + message)
{
    //
}
