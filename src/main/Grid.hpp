#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

// Template classes must be completely in the header.
// Otherwise, undefined reference errors.

template<typename T>
class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<T> > elements;

public:
    Grid(int width, int height);
    int getWidth();
    int getHeight();
    T get(int x, int y);
    void set(int x, int y, T element);
};

template<typename T>
Grid<T>::Grid(int width, int height)
    : width(width)
    , height(height)
    , elements(width, std::vector<T>(height))
{
    //
}

template<typename T>
int Grid<T>::getWidth(){
    return width;
}

template<typename T>
int Grid<T>::getHeight(){
    return height;
}

template<typename T>
T Grid<T>::get(int x, int y){
    return elements[x][y];
}

template<typename T>
void Grid<T>::set(int x, int y, T element){
    elements[x][y] = element;
}

#endif
