#ifndef TEXTIMAGE_HPP
#define TEXTIMAGE_HPP

#include "Grid.h"
#include "math/Coord2.h"
#include "math/Dim2.h"

class TextImage {
private:
    Dim2 dim;
    Grid<char> chars;

public:
    TextImage(Dim2 dim);
    void setChar(Coord2 coord, char c);
    char getChar(Coord2 coord);
};

#endif
