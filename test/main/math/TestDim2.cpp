#include "gtest/gtest.h"

#include <tuple>

#include "math/Dim2.h"
#include "math/DimException.h"

class TestDim2ConstructorThrowsParam : public testing::TestWithParam<std::tuple<int, int> > {
    //
};

TEST_P(TestDim2ConstructorThrowsParam, ) {
    int x;
    int y;
    std::tie(x, y) = GetParam();

    ASSERT_THROW(Dim2(x, y), DimException);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestDim2ConstructorThrowsParam,
    testing::Values(
        std::make_tuple(0, 0)
        , std::make_tuple(-1, 1)
        , std::make_tuple(1, -1)
        , std::make_tuple(-1, -1)
    )
);

class TestDim2LessThanParam : public testing::TestWithParam<std::tuple<Dim2, Dim2, bool> > {
    //
};

TEST_P(TestDim2LessThanParam, ) {
    Dim2 a;
    Dim2 b;
    bool expectedLessThan;
    std::tie(a, b, expectedLessThan) = GetParam();

    ASSERT_EQ(expectedLessThan, a < b);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestDim2LessThanParam,
    testing::Values(
        std::make_tuple(Dim2(0, 0), Dim2(1, 1), true)
        , std::make_tuple(Dim2(0, 0), Dim2(0, 0), false)
        , std::make_tuple(Dim2(0, 0), Dim2(1, 0), false)
        , std::make_tuple(Dim2(0, 0), Dim2(0, 1), false)
        , std::make_tuple(Dim2(0, 0), Dim2(2, 0), false)
        , std::make_tuple(Dim2(0, 1), Dim2(0, 0), false)
        , std::make_tuple(Dim2(1, 0), Dim2(0, 0), false)
        , std::make_tuple(Dim2(1, 1), Dim2(0, 0), false)
        , std::make_tuple(Dim2(1, 2), Dim2(2, 1), false)
        , std::make_tuple(Dim2(2, 0), Dim2(0, 0), false)
        , std::make_tuple(Dim2(2, 1), Dim2(1, 2), false)
    )
);

class TestDim2LessOrEqualParam : public testing::TestWithParam<std::tuple<Dim2, Dim2, bool> > {
    //
};

TEST_P(TestDim2LessOrEqualParam, ) {
    Dim2 a;
    Dim2 b;
    bool expectedLessOrEqual;
    std::tie(a, b, expectedLessOrEqual) = GetParam();

    ASSERT_EQ(expectedLessOrEqual, a <= b);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestDim2LessOrEqualParam,
    testing::Values(
        std::make_tuple(Dim2(0, 0), Dim2(0, 0), true)
        , std::make_tuple(Dim2(0, 0), Dim2(1, 0), true)
        , std::make_tuple(Dim2(0, 0), Dim2(0, 1), true)
        , std::make_tuple(Dim2(0, 0), Dim2(1, 1), true)
        , std::make_tuple(Dim2(0, 0), Dim2(2, 0), true)
        , std::make_tuple(Dim2(1, 2), Dim2(2, 1), false)
        , std::make_tuple(Dim2(1, 0), Dim2(0, 0), false)
        , std::make_tuple(Dim2(0, 1), Dim2(0, 0), false)
        , std::make_tuple(Dim2(1, 1), Dim2(0, 0), false)
        , std::make_tuple(Dim2(2, 0), Dim2(0, 0), false)
        , std::make_tuple(Dim2(2, 1), Dim2(1, 2), false)
    )
);
