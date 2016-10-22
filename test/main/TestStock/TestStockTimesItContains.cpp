#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, TimesItContainsWhenBothEmptyShouldReturnZero) {
    Stock stockA;

    int result = stockA.timesItContains(Stock());

    ASSERT_EQ(0, result);
}

TEST(TestStock, TimesItContainsWhenFirstEmptyShouldReturnZero) {
    Stock stockA;

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(0, result);
}

TEST(TestStock, TimesItContainsWhenFirstNotEnoughShouldReturnZero) {
    Stock stockA({{Resource::PERSON, 1}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 2}}));

    ASSERT_EQ(0, result);
}

TEST(TestStock, TimesItContainsWhenSameShouldBeOne) {
    Stock stockA({{Resource::PERSON, 1}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(1, result);
}

TEST(TestStock, TimesItContainsWhenDoubleShouldBeTwo) {
    Stock stockA({{Resource::PERSON, 2}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(2, result);
}

TEST(TestStock, TimesItContainsWhenDifferentResourceShouldBeZero) {
    Stock stockA({{Resource::PERSON, 1}});

    int result = stockA.timesItContains(Stock({{Resource::ELECTRICITY, 1}}));

    ASSERT_EQ(0, result);
}

TEST(TestStock, TimesItContainsWhenExtraResourceShouldHaveNoEffect) {
    Stock stockA({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(1, result);
}

TEST(TestStock, TimesItContainsWhenComplexStocks) {
    Stock stockA({{Resource::PERSON, 4}, {Resource::ELECTRICITY, 5}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 3}}));

    ASSERT_EQ(1, result);
}
