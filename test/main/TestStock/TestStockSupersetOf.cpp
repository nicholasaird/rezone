#include <tuple>

#include "gtest/gtest.h"

#include "Stock.h"

class TestStockSupersetOfParam : public testing::TestWithParam<std::tuple<Stock, Stock, bool> > {
    //
};

TEST_P(TestStockSupersetOfParam, ) {
    Stock stockA;
    Stock stockB;
    bool expected;
    std::tie(stockA, stockB, expected) = GetParam();

    ASSERT_EQ(expected, stockA.supersetOf(stockB));
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestStockSupersetOfParam,
    testing::Values(
        std::make_tuple(
            Stock()
            , Stock()
            , true
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock()
            , true
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 1}})
            , true
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 2}})
            , Stock({{Resource::PERSON, 1}})
            , true
        )
        , std::make_tuple(
            Stock()
            , Stock({{Resource::PERSON, 1}})
            , false
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::PERSON, 2}})
            , false
        )
        , std::make_tuple(
            Stock({{Resource::PERSON, 1}})
            , Stock({{Resource::ELECTRICITY, 1}})
            , false
        )
    )
);
