#ifndef COORD2_HPP
#define COORD2_HPP

#include <iostream>

struct Coord2 {
    int x;
    int y;
    Coord2();
    Coord2(const Coord2& other) = default;
    Coord2& operator=(const Coord2& other) = default;
    Coord2& operator=(Coord2&& other) noexcept = default;
    ~Coord2() = default;

    Coord2(int x, int y);
};

std::ostream& operator<<(std::ostream& stream, Coord2 coord);
bool operator<(const Coord2& lhs, const Coord2& rhs);
bool operator<=(const Coord2& lhs, const Coord2& rhs);
bool operator==(const Coord2& lhs, const Coord2& rhs);

#endif
