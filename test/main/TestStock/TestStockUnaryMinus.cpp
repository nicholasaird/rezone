#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, UnaryMinusWhenEmptyShouldReturnEmpty) {
    Stock stockA;

    Stock result = -stockA;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, UnaryMinusShouldReturnNegative) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = -stockA;

    ASSERT_EQ(Stock({{Resource::PERSON, -1}}), result);
}

TEST(TestStock, UnaryMinusWhenNegativeShouldReturnPositive) {
    Stock stockA({{Resource::PERSON, -1}});

    Stock result = -stockA;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}
