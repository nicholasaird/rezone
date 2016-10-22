#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockDivEqualParam : public testing::TestWithParam<std::tuple<Stock, int , Stock> > {
    //
};

TEST_P(TestStockDivEqualParam, ) {
    Stock stockA;
    int div;
    Stock expected;
    std::tie(stockA, div, expected) = GetParam();

    Stock result = stockA;
    result /= div;

    ASSERT_EQ(expected, result);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockDivEqualParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , 1
            , Stock()
        )
        , std::make_tuple(
            Stock()
            , 2
            , Stock()
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , 1
            , Stock({{Resource::PERSON, 1}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , 2
            , Stock()
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 2}})
            , 2
            , Stock({{Resource::PERSON, 1}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 3}})
            , 2
            , Stock({{Resource::PERSON, 1}})
        )
    )
);
