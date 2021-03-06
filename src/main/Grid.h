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
    T& operator()(int x, int y);
    void setAll(T val);
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
int Grid<T>::getWidth() {
    return width;
}

template<typename T>
int Grid<T>::getHeight() {
    return height;
}

template<typename T>
T& Grid<T>::operator()(int x, int y) {
    return elements[x][y];
}

template<typename T>
void Grid<T>::setAll(T val) {
    for(int x = 0; x<width; x++) {
        for(int y = 0; y<height; y++) {
            operator()(x, y) = val;
        }
    }
}

#endif
