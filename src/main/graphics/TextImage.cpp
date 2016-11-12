#include "TextImage.h"

#include <string>

#include "Grid.h"
#include "ImageException.h"

TextImage::TextImage(Dim2 dim)
    : dim(dim)
    , chars(dim.x, dim.y)
{
    chars.setAll(' ');
}

void TextImage::setChar(Coord2 coord, char c) {
    chars(coord.x, coord.y) = c;
}

char TextImage::getChar(Coord2 coord) {
    return chars(coord.x, coord.y);
}
