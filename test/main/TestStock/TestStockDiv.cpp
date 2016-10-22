#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, DivWhenEmptyShouldReturnEmpty) {
    Stock stockA;

    Stock result = stockA / 1;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, DivWhenEmptyShouldReturnEmpty2) {
    Stock stockA;

    Stock result = stockA / 2;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, DivWhenDivByOneShouldReturnSame) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA / 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, DivWhenSmallShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA / 2;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, DivShouldReturnHalf) {
    Stock stockA({{Resource::PERSON, 2}});

    Stock result = stockA / 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, DivShouldReturnHalfRoundedDown) {
    Stock stockA({{Resource::PERSON, 3}});

    Stock result = stockA / 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}
