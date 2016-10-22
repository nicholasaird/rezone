#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockEqualParam : public testing::TestWithParam<std::tuple<Stock, Stock> > {
    //
};

TEST_P(TestStockEqualParam, ) {
    Stock stockA;
    Stock stockB;
    std::tie(stockA, stockB) = GetParam();

    ASSERT_EQ(stockA, stockB);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockEqualParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , Stock()
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 0}})
            , Stock()
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 1}})
        )
    )
);
