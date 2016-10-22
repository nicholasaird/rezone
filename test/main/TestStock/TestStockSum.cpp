#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockSumParam : public testing::TestWithParam<std::tuple<Stock, int> > {
    //
};

TEST_P(TestStockSumParam, ) {
    Stock stockA;
    int expected;
    std::tie(stockA, expected) = GetParam();

    ASSERT_EQ(expected, stockA.sum());
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockSumParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , 0
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , 1
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 2}})
            , 2
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 20000}})
            , 20000
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}})
            , 2
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}, {Resource::IND_PRODUCT, 1}})
            , 3
        )
    )
);
