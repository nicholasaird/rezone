#ifndef DIM2_HPP
#define DIM2_HPP

#include <iostream>

struct Dim2 {
    int x;
    int y;

    Dim2();
    Dim2(const Dim2& other) = default;
    Dim2& operator=(const Dim2& other) = default;
    Dim2& operator=(Dim2&& other) noexcept = default;
    ~Dim2() = default;

    Dim2(int x, int y);
};

std::ostream& operator<<(std::ostream& stream, Dim2 dim);
bool operator<(const Dim2& lhs, const Dim2& rhs);
bool operator<=(const Dim2& lhs, const Dim2& rhs);
bool operator==(const Dim2& lhs, const Dim2& rhs);

#endif
