#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, TimesEqualWhenEmptyAndByZeroShouldMakeEmpty) {
    Stock stockA;

    stockA *= 0;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesEqualWhenEmptyShouldMakeEmpty) {
    Stock stockA;

    stockA *= 1;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesEqualWhenEmptyShouldMakeEmpty2) {
    Stock stockA;

    stockA *= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesEqualWhenByZeroShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 0;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesEqualWhenByOneShouldMakeSame) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, TimesEqualWhenByTwoShouldDouble) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), stockA);
}
