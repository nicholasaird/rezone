#include "TextImage.h"

#include <string>

#include "Grid.h"
#include "ImageException.h"

TextImage::TextImage(int width, int height)
    : width(width)
    , height(height)
    , chars(width, height)
{
    if(width <= 0 || height <= 0) {
        throw ImageException("Dimensions must be greater than zero: ("
            + std::to_string(width) + ", "
            + std::to_string(height) + ")");
    }
}

void TextImage::setChar(Coord2 coord, char c) {
    chars(coord.x, coord.y) = c;
}

char TextImage::getChar(Coord2 coord) {
    return chars(coord.x, coord.y);
}
