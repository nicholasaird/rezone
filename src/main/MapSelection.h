#ifndef MAPSELECTION_HPP
#define MAPSELECTION_HPP

#include <set>
#include <tuple>

class MapSelection {
private:
    std::set<std::tuple<int, int> > selected;

public:
    MapSelection();
    void add(int x, int y);
    void remove(int x, int y);
    bool isSelected(int x, int y) const;
    const std::set<std::tuple<int, int> > getSelectedSet() const;
};

#endif
