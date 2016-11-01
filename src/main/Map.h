#ifndef MAP_HPP
#define MAP_HPP

#include <memory>  // smart pointer

#include "Grid.h"
#include "Zone.h"

class Map {
private:
    Grid<std::shared_ptr<Zone> > zones;

public:
    Map(int width, int height);
};

#endif
