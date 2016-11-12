#include "Coord2.h"

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
