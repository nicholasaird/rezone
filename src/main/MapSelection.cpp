#include "MapSelection.h"

MapSelection::MapSelection()
    : selected()
{
    //
}

void MapSelection::add(int x, int y) {
    std::tuple<int, int> point = std::make_tuple(x, y);
    selected.insert(point);
}

bool MapSelection::isSelected(int x, int y) const {
    std::tuple<int, int> point = std::make_tuple(x, y);
    return selected.find(point) != selected.end();
}

const std::set<std::tuple<int, int> > MapSelection::getSelectedSet() const {
    return selected;
}
