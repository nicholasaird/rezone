#include "gtest/gtest.h"

#include "graphics/TextImage.h"
#include "graphics/ImageException.h"
#include "math/Coord2.h"
#include "math/Dim2.h"

TEST(TestTextImage, InsertChar) {
    TextImage image(Dim2(1, 1));

    image.setChar(Coord2(0, 0), 'a');

    ASSERT_EQ('a', image.getChar(Coord2(0, 0)));
}

TEST(TestTextImage, InsertChar2) {
    TextImage image(Dim2(1, 1));

    image.setChar(Coord2(0, 0), 'b');

    ASSERT_EQ('b', image.getChar(Coord2(0, 0)));
}

TEST(TestTextImage, InsertChar3) {
    TextImage image(Dim2(1, 1));

    image.setChar(Coord2(0, 0), 'a');
    image.setChar(Coord2(0, 0), 'b');

    ASSERT_EQ('b', image.getChar(Coord2(0, 0)));
}
