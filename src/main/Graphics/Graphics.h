#ifndef TEXTGRAPHICS_HPP
#define TEXTGRAPHICS_HPP

#include <iostream>

#include "TextImage.h"

class TextGraphics {
public:
    TextGraphics(std::ostream out);
    void clear();
    void render(TextImage& image);
    void swapBuffer();
};

#endif
