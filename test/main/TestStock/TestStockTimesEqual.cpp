#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockTimesEqualParam : public testing::TestWithParam<std::tuple<Stock, int, Stock> > {
    //
};

TEST_P(TestStockTimesEqualParam, ) {
    Stock stockA;
    int mult;
    Stock expected;
    std::tie(stockA, mult, expected) = GetParam();

    stockA *= mult;

    ASSERT_EQ(expected, stockA);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockTimesEqualParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , 0
            , Stock()
        )
        , std::make_tuple(
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
            , 0
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
            , Stock({{Resource::PERSON, 2}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}})
            , 2
            , Stock({{Resource::PERSON, 2}, {Resource::ELECTRICITY, 2}})
        )
    )
);
