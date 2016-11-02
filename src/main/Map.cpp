#include "Map.h"

Map::Map(int width, int height)
    : zones(width, height)
    , width(width)
    , height(height)
{
    //
}

int Map::getWidth() {
    return width;
}

int Map::getHeight() {
    return height;
}
