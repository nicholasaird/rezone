#include<tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockMinusParam : public testing::TestWithParam<std::tuple<Stock, Stock, Stock> > {
    //
};

TEST_P(TestStockMinusParam, ) {
    Stock stockA;
    Stock stockB;
    Stock expected;
    std::tie(stockA, stockB, expected) = GetParam();

    ASSERT_EQ(expected, stockA - stockB);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockMinusParam,
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
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::ELECTRICITY, 1}})
            , Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, -1}})
        )
    )
);
