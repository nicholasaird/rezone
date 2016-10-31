#include <vector>

#include "gtest/gtest.h"

template<typename T>
std::vector<T> getTail(std::vector<T> vec) {
    return {vec.begin() + 1, vec.end()};
}

TEST(TestVector, TailOfVectorWithOneElement) {
    std::vector<int> vec = {1};
    std::vector<int> tail = getTail(vec);

    std::vector<int> expected;
    ASSERT_EQ(expected, tail);
}
