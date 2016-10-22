#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockUnaryMinusParam : public testing::TestWithParam<std::tuple<Stock, Stock> > {
    //
};

TEST_P(TestStockUnaryMinusParam, ) {
    Stock stockA;
    Stock expected;
    std::tie(stockA, expected) = GetParam();

    ASSERT_EQ(expected, -stockA);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockUnaryMinusParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , Stock()
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, -1}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 2}})
            , Stock({{Resource::PERSON, -2}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, -1}})
            , Stock({{Resource::PERSON, 1}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 2}})
            , Stock({{Resource::PERSON, -1}, {Resource::ELECTRICITY, -2}})
        )
    )
);
