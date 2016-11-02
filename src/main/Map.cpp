#include "Map.h"

Map::Map(int width, int height)
    : zones(width, height)
    , width(width)
    , height(height)
{
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < width; y++) {
            zones(x, y) = std::make_shared<Zone>("Empty", StockPair());
        }
    }
}

int Map::getWidth() {
    return width;
}

int Map::getHeight() {
    return height;
}

std::shared_ptr<Zone> Map::getZone(const Coord2& coord) {
    return zones(coord.x, coord.y);
}
