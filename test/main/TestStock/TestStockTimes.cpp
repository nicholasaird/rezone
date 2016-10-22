#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, TimesWhenEmptyByZeroShouldReturnEmpty) {
    Stock stockA;

    Stock result = stockA * 0;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, TimesWhenEmptyShouldReturnEmpty) {
    Stock stockA;

    Stock result = stockA * 1;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, TimesWhenEmptyShouldReturnEmpty2) {
    Stock stockA;

    Stock result = stockA * 2;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, TimesWhenByZeroShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 0;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, TimesWhenByOneShouldReturnSame) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, TimesWhenMultTwoShouldReturnDouble) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), result);
}

TEST(TestStock, TimesWhenMultTwoShouldReturnDouble2) {
    Stock stockA({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}});

    Stock result = stockA * 2;

    ASSERT_EQ(
        Stock({{Resource::PERSON, 2}, {Resource::ELECTRICITY, 2}}),
        result
    );
}
