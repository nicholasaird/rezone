#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStockPlus, PlusWhenWithNegativeOfItselfShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA + -stockA;

    ASSERT_EQ(Stock(), result);
}

class TestStockPlusParam : public testing::TestWithParam<std::tuple<Stock, Stock, Stock> > {
    //
};

TEST_P(TestStockPlusParam, ) {
    Stock stockA;
    Stock stockB;
    Stock expected;
    std::tie(stockA, stockB, expected) = GetParam();

    ASSERT_EQ(expected, stockA + stockB);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockPlusParam,
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
