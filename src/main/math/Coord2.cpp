#include "Coord2.h"

#include "CoordException.h"

Coord2::Coord2()
    : x(0)
    , y(0)
{
    //
}

Coord2::Coord2(int x, int y)
    : x(x)
    , y(y)
{
    if(x < 0 || y < 0) {
        throw CoordException(x, y, "Values must be greater or equal to zero");
    }
}

std::ostream& operator<<(std::ostream& stream, Coord2 coord) {
    stream << "(" << coord.x << ", " << coord.y << ")";

    return stream;
}

bool operator<(const Coord2& lhs, const Coord2& rhs) {
    return lhs.x < rhs.x && lhs.y < rhs.y;
}

bool operator<=(const Coord2& lhs, const Coord2& rhs) {
    return lhs.x <= rhs.x && lhs.y <= rhs.y;
}

bool operator==(const Coord2& lhs, const Coord2& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
