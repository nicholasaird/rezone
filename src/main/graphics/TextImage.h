#ifndef TEXTIMAGE_HPP
#define TEXTIMAGE_HPP

#include "Grid.h"
#include "math/Coord2.h"

class TextImage {
private:
    int width;
    int height;
    Grid<char> chars;

public:
    TextImage(int w, int h);
    void setChar(Coord2 coord, char c);
    char getChar(Coord2 coord);
};

#endif
