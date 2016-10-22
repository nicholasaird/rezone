#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockTimesItContainsParam : public testing::TestWithParam<std::tuple<Stock, Stock, int> > {
    //
};

TEST_P(TestStockTimesItContainsParam, ) {
    Stock stockA;
    Stock stockB;
    int expected;
    std::tie(stockA, stockB, expected) = GetParam();

    ASSERT_EQ(expected, stockA.timesItContains(stockB));
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockTimesItContainsParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , Stock()
            , 0
        )
        , std::make_tuple(
            Stock()
            , Stock({{Resource::PERSON, 1}})
            , 0
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 2}})
            , 0
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 1}})
            , 1
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 2}})
            , Stock({{Resource::PERSON, 1}})
            , 2
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::ELECTRICITY, 1}})
            , 0
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}})
            , Stock({{Resource::PERSON, 1}})
            , 1
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 4}, {Resource::ELECTRICITY, 5}})
            , Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 3}})
            , 1
        )
    )
);
