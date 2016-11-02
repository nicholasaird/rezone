#ifndef COORD2_HPP
#define COORD2_HPP

#include <iostream>

struct Coord2 {
    int x;
    int y;
    Coord2() : x(0), y(0) {/* */};
    Coord2(int x, int y) : x(x), y(y) {/* */};
};

std::ostream& operator<<(std::ostream& stream, Coord2 coord);
bool operator<(const Coord2& lhs, const Coord2& rhs);
bool operator==(const Coord2& lhs, const Coord2& rhs);

#endif
