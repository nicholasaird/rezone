#include <string>
#include <tuple>

#include "gtest/gtest.h"
#include "Grid.h"
#include "Zone.h"

TEST(TestGrid, ShouldReturnValueStored) {
    Grid<int> grid(1, 1);

    grid(0, 0) = 10;
    int result = grid(0, 0);

    ASSERT_EQ(10, result);
}

TEST(TestGrid, ShouldOverwriteValue) {
    Grid<int> grid(1, 1);

    grid(0, 0) = 10;
    grid(0, 0) = 20;
    int result = grid(0, 0);

    ASSERT_EQ(20, result);
}

TEST(TestGrid, IntValueStoredShouldBeACopy) {
    Grid<int> grid(1, 1);

    int value = 10;
    grid(0, 0) = value;
    value = 20;

    ASSERT_EQ(10, grid(0, 0));
}

TEST(TestGrid, StringValueStoredShouldBeACopy) {
    Grid<std::string> grid(1, 1);

    std::string value = "hello";
    grid(0, 0) = value;
    value = "externally-changed";

    ASSERT_EQ("hello", grid(0, 0));
}

TEST(TestGrid, ObjecValueStoredShouldBeACopy) {
    class MyObject {
    public:
        int value;
    };

    Grid<MyObject> grid(1, 1);

    MyObject myObject;
    myObject.value = 10;
    grid(0, 0) = myObject;
    myObject.value = 20;

    ASSERT_EQ(10, grid(0, 0).value);
}

TEST(TestGrid, ShouldStoresValuesCorrectly) {
    Grid<int> grid(1, 2);

    grid(0, 0) = 10;
    grid(0, 1) = 20;

    ASSERT_EQ(10, grid(0, 0));
    ASSERT_EQ(20, grid(0, 1));
}

TEST(TestGrid, ShouldStoresValuesCorrectly2) {
    Grid<int> grid(2, 2);

    grid(0, 0) = 0;
    grid(0, 1) = 1;
    grid(1, 0) = 10;
    grid(1, 1) = 11;

    ASSERT_EQ(0, grid(0, 0));
    ASSERT_EQ(1, grid(0, 1));
    ASSERT_EQ(10, grid(1, 0));
    ASSERT_EQ(11, grid(1, 1));
}

class TestGridDimensionsParam : public testing::TestWithParam<std::tuple<int, int> > {
    //
};

TEST_P(TestGridDimensionsParam, ) {
    int width;
    int height;
    std::tie(width, height) = GetParam();
    int expectedWidth = width;
    int expectedHeight = height;

    Grid<int> grid(width, height);

    ASSERT_EQ(expectedWidth, grid.getWidth());
    ASSERT_EQ(expectedHeight, grid.getHeight());
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestGridDimensionsParam,
    testing::Values(
        std::make_tuple(
            0
            , 0
        )
        , std::make_tuple(
            1
            , 1
        )
        , std::make_tuple(
            2
            , 1
        )
        , std::make_tuple(
            10
            , 25
        )
    )
);
