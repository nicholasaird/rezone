#include "gtest/gtest.h"

#include <map>

TEST(TestMap, WhenIterationByReferenceShouldChangeValue) {
    std::map<int, int> map({{1, 1}});

    for(auto& pair : map) {
        pair.second = 2;
    }

    ASSERT_EQ(2, map[1]);
}

TEST(TestMap, WhenIterationByValueShouldNotChangeValue) {
    std::map<int, int> map({{1, 1}});

    for(auto pair : map) {
        pair.second = 2;
    }

    ASSERT_EQ(1, map[1]);
}
