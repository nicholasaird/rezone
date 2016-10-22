#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, PlusEmptyWhenBothEmptyShouldMakeEmpty) {
    Stock stockA;
    Stock stockB;

    stockA += stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, PlusEqualWhenSecondEmptyShouldMakeFirst) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, PlusEqualWhenFirstEmptyShouldMakeSecond) {
    Stock stockA;
    Stock stockB({{Resource::PERSON, 1}});

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, PlusEqualWhenDifferentCountsShouldMakeSum) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 2}});

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 3}}), stockA);
}

TEST(TestStock, PlusEqualWhenDifferentResourcesShouldMakeSum) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::ELECTRICITY, 1}});

    stockA += stockB;

    ASSERT_EQ(
        Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}}),
        stockA
    );
}

TEST(TestStock, PlusEqualWhenWithNegativeEquivalentShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, -1}});

    stockA += stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, PlusEqualWhenWithItsNegativeShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA += -stockA;

    ASSERT_EQ(Stock(), stockA);
}
