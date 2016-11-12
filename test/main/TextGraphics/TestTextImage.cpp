#include "gtest/gtest.h"

#include "Graphics/TextImage.h"
#include "Graphics/ImageException.h"

TEST(TestTextImage, ConstructorShouldThrow) {
    ASSERT_THROW(TextImage(0, 0), ImageException);
}

TEST(TestTextImage, ConstructorShouldThrow2) {
    ASSERT_THROW(TextImage(-1, 1), ImageException);
}

TEST(TestTextImage, ConstructorShouldThrow3) {
    ASSERT_THROW(TextImage(1, -1), ImageException);
}

TEST(TestTextImage, ConstructorShouldThrow4) {
    ASSERT_THROW(TextImage(-1, -1), ImageException);
}

TEST(TestTextImage, InsertChar) {
    TextImage image(1, 1);

    image.setChar(Coord2(0, 0), 'a');

    ASSERT_EQ('a', image.getChar(Coord2(0, 0)));
}

TEST(TestTextImage, InsertChar2) {
    TextImage image(1, 1);

    image.setChar(Coord2(0, 0), 'b');

    ASSERT_EQ('b', image.getChar(Coord2(0, 0)));
}

TEST(TestTextImage, InsertChar3) {
    TextImage image(1, 1);

    image.setChar(Coord2(0, 0), 'a');
    image.setChar(Coord2(0, 0), 'b');

    ASSERT_EQ('b', image.getChar(Coord2(0, 0)));
}
