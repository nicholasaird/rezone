#include "InvalidCoordinateException.h"

InvalidCoordinateException::InvalidCoordinateException(int x, int y, int maxWidth, int maxHeight)
    : runtime_error(
        "Invalid coordinate: (" + std::to_string(x) + "," + std::to_string(y) + "), max ("
        + std::to_string(maxWidth) + ", " + std::to_string(maxHeight) + ")")
{
    //
}
