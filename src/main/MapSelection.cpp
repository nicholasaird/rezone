#include "MapSelection.h"

MapSelection::MapSelection()
    : selected()
{
    //
}

void MapSelection::clear() {
    selected.clear();
}

void MapSelection::add(Coord2 coord) {
    selected.insert(coord);
}

void MapSelection::remove(Coord2 coord) {
    selected.erase(coord);
}

bool MapSelection::isSelected(Coord2 coord) const {
    return selected.find(coord) != selected.end();
}

const std::set<Coord2> MapSelection::getSelectedSet() const {
    return selected;
}
