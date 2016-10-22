#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStockSubsetOf, ShouldBeSubsetOfItself) {
    Stock stockA({{Resource::PERSON, 1}});

    ASSERT_TRUE(stockA.subsetOf(stockA));
}

class TestStockSubsetOfParam : public testing::TestWithParam<std::tuple<Stock, Stock, bool> > {
    //
};

TEST_P(TestStockSubsetOfParam, ) {
    Stock stockA;
    Stock stockB;
    bool expected;
    std::tie(stockA, stockB, expected) = GetParam();

    ASSERT_EQ(expected, stockA.subsetOf(stockB));
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockSubsetOfParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , Stock()
            , true
        )
        , std::make_tuple(
            Stock()
            , Stock({{Resource::PERSON, 1}})
            , true
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 1}})
            , true
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 2}})
            , true
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock()
            , false
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 2}})
            , Stock({{Resource::PERSON, 1}})
            , false
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::ELECTRICITY, 1}})
            , false
        )
    )
);
