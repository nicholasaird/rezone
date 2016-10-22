#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockTimesParam : public testing::TestWithParam<std::tuple<Stock, int, Stock> > {
    //
};

TEST_P(TestStockTimesParam, ) {
    Stock stockA;
    int mult;
    Stock expected;
    std::tie(stockA, mult, expected) = GetParam();

    ASSERT_EQ(expected, stockA * mult);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockTimesParam,
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
