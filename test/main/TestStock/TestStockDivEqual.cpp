#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, DivEqualWhenEmptyAndShouldMakeEmpty) {
    Stock stockA;

    stockA /= 1;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, DivEqualWhenEmptyAndShouldMakeEmpty2) {
    Stock stockA;

    stockA /= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, DivEqualWhenByOneShouldMakeSame) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA /= 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, DivEqualWhenSmallCountAndByTwoShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA /= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, DivEqualWhenByTwoShouldMakeHalf) {
    Stock stockA({{Resource::PERSON, 2}});

    stockA /= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, DivEqualWhenByTwoShouldMakeHalfRoundedDown) {
    Stock stockA({{Resource::PERSON, 3}});

    stockA /= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}
