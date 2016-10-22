#include<tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockNotEqualParam : public testing::TestWithParam<std::tuple<Stock, Stock> > {
    //
};

TEST_P(TestStockNotEqualParam, ) {
    Stock stockA;
    Stock stockB;
    std::tie(stockA, stockB) = GetParam();

    ASSERT_NE(stockA, stockB);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockNotEqualParam,
    testing::Values(
        std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock()
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::ELECTRICITY, 1}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 2}})
        )
    )
);
