#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStockMinusEqual, MinusEqualWithItself) {
    Stock stockA({{Resource::PERSON, 2}});

    stockA -= stockA;

    ASSERT_EQ(Stock(), stockA);
}

class TestStockMinusEqualParam : public testing::TestWithParam<std::tuple<Stock, Stock, Stock> > {
    //
};

TEST_P(TestStockMinusEqualParam, ) {
    Stock stockA;
    Stock stockB;
    Stock expected;
    std::tie(stockA, stockB, expected) = GetParam();

    stockA -= stockB;

    ASSERT_EQ(expected, stockA);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockMinusEqualParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , Stock()
            , Stock()
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock()
            , Stock({{Resource::PERSON, 1}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 1}})
            , Stock()
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 2}})
            , Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 1}})
        )
    )
);
