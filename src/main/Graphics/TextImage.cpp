#include "TextImage.h"

#include <string>

#include "ImageException.h"

TextImage::TextImage(int width, int height)
    : width(width)
    , height(height)
{
    if(width <= 0 || height <= 0) {
        throw ImageException("Dimensions must be greater than zero: ("
            + std::to_string(width) + ", "
            + std::to_string(height) + ")");
    }
}
