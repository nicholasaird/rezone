#include <string>

#include "gtest/gtest.h"
#include "Grid.hpp"
#include "Zone.hpp"

TEST(TestGrid, ShouldReturnValueStored) {
    Grid<int> grid(1, 1);

    grid(0, 0) = 10;
    int result = grid(0, 0);

    ASSERT_EQ(10, result);
}

TEST(TestGrid, CanOverwriteValue) {
    Grid<int> grid(1, 1);

    grid(0, 0) = 10;
    grid(0, 0) = 20;
    int result = grid(0, 0);

    ASSERT_EQ(20, result);
}

TEST(TestGrid, IntValueStoredIsACopy) {
    Grid<int> grid(1, 1);

    int value = 10;
    grid(0, 0) = value;
    value = 20;

    ASSERT_EQ(10, grid(0, 0));
}

TEST(TestGrid, StringValueStoredIsACopy) {
    Grid<std::string> grid(1, 1);

    std::string value = "hello";
    grid(0, 0) = value;
    value = "externally-changed";

    ASSERT_EQ("hello", grid(0, 0));
}

TEST(TestGrid, OneDimensionalGridStoresValuesCorrectly) {
    Grid<int> grid(1, 2);

    grid(0, 0) = 10;
    grid(0, 1) = 20;

    ASSERT_EQ(10, grid(0, 0));
    ASSERT_EQ(20, grid(0, 1));
}

TEST(TestGrid, TwoDimensionalGridStoresValuesCorrectly) {
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
