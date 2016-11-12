#include "Dim2.h"

#include "DimException.h"

Dim2::Dim2()
    : x(1)
    , y(1)
{
    //
}

Dim2::Dim2(int x, int y)
    : x(x)
    , y(y)
{
    if(x <= 0 || y <=0 ) {
        throw DimException(x, y, "Dimensions should be greater than zero");
    }
}

std::ostream& operator<<(std::ostream& stream, Dim2 dim) {
    stream << "Dim2(" << dim.x << ", " << dim.y << ")";

    return stream;
}

bool operator<(const Dim2& lhs, const Dim2& rhs) {
    return lhs.x < rhs.x && lhs.y < rhs.y;
}

bool operator<=(const Dim2& lhs, const Dim2& rhs) {
    return lhs.x <= rhs.x && lhs.y <= rhs.y;
}

bool operator==(const Dim2& lhs, const Dim2& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
