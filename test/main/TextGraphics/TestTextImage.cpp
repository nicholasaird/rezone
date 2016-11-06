#include "gtest/gtest.h"

#include "Graphics/TextImage.h"
#include "Graphics/ImageException.h"

TEST(TestTextGraphics, TestDimensions) {
    ASSERT_THROW(TextImage(0, 0), ImageException);
}
