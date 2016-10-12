#include "gtest/gtest.h"
#include "Grid.hpp"
#include "Zone.hpp"

TEST(TestGrid, ShouldReturnValueStored) {
    Grid<int> grid(1, 1);

    grid.set(0, 0, 10);
    int result = grid.get(0, 0);

    ASSERT_EQ(10, result);
}
