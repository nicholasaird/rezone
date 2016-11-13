#include "CoordException.h"

#include <string>

CoordException::CoordException(int x, int y, std::string message)
    : runtime_error(
        "Coord2(" + std::to_string(x) + "," + std::to_string(y) + "): " + message)
{
    //
}
