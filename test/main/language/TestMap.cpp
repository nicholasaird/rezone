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

TEST(TestMap, WhenIteratingByReferenceAndEraseShouldWork) {
    std::map<int, int> map({{1, 1}});

    for(auto& pair : map) {
        map.erase(pair.first);
    }

    ASSERT_EQ(0, map.count(1));
}

TEST(TestMap, WhenIteratingByReferenceAndEraseShouldWork2) {
    std::map<int, int> map({{1, 1}, {10, 10}});

    for(auto& pair : map) {
        if(pair.first == 1) {
            map.erase(pair.first);
        }
        else {
            pair.second = 20;
        }
    }

    ASSERT_EQ(0, map.count(1));
    ASSERT_EQ(20, map[10]);
}
