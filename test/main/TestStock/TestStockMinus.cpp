#include "gtest/gtest.h"

#include "Stock.h"

namespace MinusTest {
    class MinusTest : public testing::TestWithParam<std::tuple<Stock, Stock, Stock> > {
        //
    };

    TEST_P(MinusTest, ) {
        auto params = GetParam();
        Stock stockA = std::get<0>(params);
        Stock stockB = std::get<1>(params);
        Stock expected = std::get<2>(params);

        ASSERT_EQ(expected, stockA - stockB);
    }

    INSTANTIATE_TEST_CASE_P(
        /* */,
        MinusTest,
        testing::Values(
            std::tuple<Stock, Stock, Stock>(
                Stock()
                , Stock()
                , Stock()
            )
            , std::tuple<Stock, Stock, Stock>(
                Stock({{Resource::PERSON, 1}})
                , Stock()
                , Stock({{Resource::PERSON, 1}})
            )
            , std::tuple<Stock, Stock, Stock>(
                Stock({{Resource::PERSON, 1}})
                , Stock({{Resource::PERSON, 1}})
                , Stock()
            )
            , std::tuple<Stock, Stock, Stock>(
                Stock({{Resource::PERSON, 2}})
                , Stock({{Resource::PERSON, 1}})
                , Stock({{Resource::PERSON, 1}})
            )
            , std::tuple<Stock, Stock, Stock>(
                Stock({{Resource::PERSON, 1}})
                , Stock({{Resource::ELECTRICITY, 1}})
                , Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, -1}})
            )
        )
    );
};
