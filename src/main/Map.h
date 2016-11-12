#ifndef MAP_HPP
#define MAP_HPP

#include <memory>  // smart pointer

#include "Grid.h"
#include "math/Coord2.h"
#include "Zone.h"

class Map {
private:
    Grid<std::shared_ptr<Zone> > zones;
    int width;
    int height;

public:
    Map(int width, int height);
    int getWidth();
    int getHeight();
    std::shared_ptr<Zone> getZone(const Coord2& coord);
};

#endif
