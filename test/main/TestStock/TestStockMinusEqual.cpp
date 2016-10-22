#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, MinusEqualWhenBothEmptyShouldMakeEmpty) {
    Stock stockA;
    Stock stockB;

    stockA -= stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, MinusEqualWhenSecondEmptyShouldMakeSame) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    stockA -= stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, MinusEqualWhenSameCountsShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    stockA -= stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, MinusEqualWhenFirstHasLargerCountShouldReturnNonEmpty) {
    Stock stockA({{Resource::PERSON, 2}});
    Stock stockB({{Resource::PERSON, 1}});

    stockA -= stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, MinusEqualWhenWithItselfShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 2}});

    stockA -= stockA;

    ASSERT_EQ(Stock(), stockA);
}
