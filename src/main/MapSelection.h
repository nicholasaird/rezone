#ifndef MAPSELECTION_HPP
#define MAPSELECTION_HPP

#include <set>

#include "math/Coord2.h"

class MapSelection {
private:
    std::set<Coord2> selected;

public:
    MapSelection();
    void clear();
    void add(Coord2 coord);
    void remove(Coord2 coord);
    bool isSelected(Coord2 coord) const;
    const std::set<Coord2> getSelectedSet() const;
};

#endif
