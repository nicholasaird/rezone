#include "gtest/gtest.h"

#include <tuple>

#include "math/Dim2.h"
#include "math/DimException.h"

class TestDim2GetValuesParam : public testing::TestWithParam<std::tuple<int, int> > {
    //
};

TEST_P(TestDim2GetValuesParam, ) {
    int x;
    int y;
    std::tie(x, y) = GetParam();
    Dim2 dim(x, y);

    ASSERT_EQ(x, dim.x);
    ASSERT_EQ(y, dim.y);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestDim2GetValuesParam,
    testing::Values(
        std::make_tuple(1, 1)
        , std::make_tuple(2, 1)
        , std::make_tuple(1, 2)
        , std::make_tuple(2, 2)
        , std::make_tuple(3, 3)
        , std::make_tuple(10, 5)
    )
);

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

class TestDim2LessThanParam : public testing::TestWithParam<std::tuple<int, int, int, int, bool> > {
    //
};

TEST_P(TestDim2LessThanParam, ) {
    int x1, y1;
    int x2, y2;
    bool expectedLessThan;
    std::tie(x1, y1, x2, y2, expectedLessThan) = GetParam();
    Dim2 a(x1, y1);
    Dim2 b(x2, y2);

    ASSERT_EQ(expectedLessThan, a < b);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestDim2LessThanParam,
    testing::Values(
        std::make_tuple(
            1, 1
            , 2, 2
            , true
        )
        , std::make_tuple(
            1, 1
            , 3, 3
            , true
        )
        , std::make_tuple(
            2, 2
            , 3, 3
            , true
        )
        , std::make_tuple(
            2, 2
            , 2, 2
            , false
        )
        , std::make_tuple(
            2, 2
            , 2, 3
            , false
        )
        , std::make_tuple(
            2, 2
            , 1, 1
            , false
        )
    )
);

class TestDim2LessOrEqualParam : public testing::TestWithParam<std::tuple<int, int, int, int, bool> > {
    //
};

TEST_P(TestDim2LessOrEqualParam, ) {
    int x1, y1;
    int x2, y2;
    bool expectedLessOrEqual;
    std::tie(x1, y1, x2, y2, expectedLessOrEqual) = GetParam();
    Dim2 a(x1, y1);
    Dim2 b(x2, y2);

    ASSERT_EQ(expectedLessOrEqual, a <= b);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestDim2LessOrEqualParam,
    testing::Values(
        std::make_tuple(
            1, 1
            , 1, 1
            , true
        )
        , std::make_tuple(
            1, 1
            , 1, 2
            , true
        )
        , std::make_tuple(
            1, 1
            , 2, 1
            , true
        )
        , std::make_tuple(
            1, 1
            , 2, 2
            , true
        )
        , std::make_tuple(
            1, 1
            , 3, 3
            , true
        )
        , std::make_tuple(
            2, 2
            , 1, 1
            , false
        )
        , std::make_tuple(
            2, 2
            , 2, 1
            , false
        )
        , std::make_tuple(
            1, 2
            , 2, 1
            , false
        )
    )
);
