#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStockPlusEqual, PlusEqualWhenWithItsNegativeShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA += -stockA;

    ASSERT_EQ(Stock(), stockA);
}

class TestStockPlusEqualParam : public testing::TestWithParam<std::tuple<Stock, Stock, Stock> > {
    //
};

TEST_P(TestStockPlusEqualParam, ) {
    Stock stockA;
    Stock stockB;
    Stock expected;
    std::tie(stockA, stockB, expected) = GetParam();

    stockA += stockB;

    ASSERT_EQ(expected, stockA);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockPlusEqualParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , Stock()
            , Stock()
        )
        , std::make_tuple(
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
            , Stock({{Resource::PERSON, 2}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::ELECTRICITY, 1}})
            , Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}})
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, -1}})
            , Stock()
        )
    )
);
