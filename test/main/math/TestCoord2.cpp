#include "gtest/gtest.h"

#include "math/Coord2.h"

class TestCoordLessThanParam : public testing::TestWithParam<std::tuple<Coord2, Coord2, bool> > {
    //
};

TEST_P(TestCoordLessThanParam, ) {
    Coord2 a;
    Coord2 b;
    bool expectedLessThan;
    std::tie(a, b, expectedLessThan) = GetParam();

    ASSERT_EQ(expectedLessThan, a < b);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestCoordLessThanParam,
    testing::Values(
        std::make_tuple(Coord2(0, 0), Coord2(1, 1), true)
        , std::make_tuple(Coord2(0, 0), Coord2(0, 0), false)
        , std::make_tuple(Coord2(0, 0), Coord2(1, 0), false)
        , std::make_tuple(Coord2(0, 0), Coord2(0, 1), false)
        , std::make_tuple(Coord2(0, 0), Coord2(2, 0), false)
        , std::make_tuple(Coord2(0, 1), Coord2(0, 0), false)
        , std::make_tuple(Coord2(1, 0), Coord2(0, 0), false)
        , std::make_tuple(Coord2(1, 1), Coord2(0, 0), false)
        , std::make_tuple(Coord2(1, 2), Coord2(2, 1), false)
        , std::make_tuple(Coord2(2, 0), Coord2(0, 0), false)
        , std::make_tuple(Coord2(2, 1), Coord2(1, 2), false)
    )
);

class TestCoordLessOrEqualParam : public testing::TestWithParam<std::tuple<Coord2, Coord2, bool> > {
    //
};

TEST_P(TestCoordLessOrEqualParam, ) {
    Coord2 a;
    Coord2 b;
    bool expectedLessOrEqual;
    std::tie(a, b, expectedLessOrEqual) = GetParam();

    ASSERT_EQ(expectedLessOrEqual, a <= b);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestCoordLessOrEqualParam,
    testing::Values(
        std::make_tuple(Coord2(0, 0), Coord2(0, 0), true)
        , std::make_tuple(Coord2(0, 0), Coord2(1, 0), true)
        , std::make_tuple(Coord2(0, 0), Coord2(0, 1), true)
        , std::make_tuple(Coord2(0, 0), Coord2(1, 1), true)
        , std::make_tuple(Coord2(0, 0), Coord2(2, 0), true)
        , std::make_tuple(Coord2(1, 2), Coord2(2, 1), false)
        , std::make_tuple(Coord2(1, 0), Coord2(0, 0), false)
        , std::make_tuple(Coord2(0, 1), Coord2(0, 0), false)
        , std::make_tuple(Coord2(1, 1), Coord2(0, 0), false)
        , std::make_tuple(Coord2(2, 0), Coord2(0, 0), false)
        , std::make_tuple(Coord2(2, 1), Coord2(1, 2), false)
    )
);
