#include <tuple>
#include <vector>

#include "gtest/gtest.h"
#include "Utils.hpp"

class TestUtilsTailParam
    : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int> > >
{
    //
};

TEST_P(TestUtilsTailParam, ) {
    std::vector<int> vec;
    std::vector<int> expected;
    std::tie(vec, expected) = GetParam();

    std::vector<int> tail = VectorUtils::getTail(vec);

    ASSERT_EQ(expected, tail);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestUtilsTailParam,
    testing::Values(
        std::make_tuple(
            std::vector<int>({1})
            , std::vector<int>({})
        )
        , std::make_tuple(
            std::vector<int>({1, 2})
            , std::vector<int>({2})
        )
        , std::make_tuple(
            std::vector<int>({1, 2, 3})
            , std::vector<int>({2, 3})
        )
    )
);
