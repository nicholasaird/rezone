#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, SubsetWhenBothEmptyShouldReturnTrue) {
    Stock stockA;
    Stock stockB;

    ASSERT_TRUE(stockA.subsetOf(stockB));
}

TEST(TestStock, SubsetWhenFirstEmptyShouldReturnTrue) {
    Stock stockA;
    Stock stockB({{Resource::PERSON, 1}});

    ASSERT_TRUE(stockA.subsetOf(stockB));
}

TEST(TestStock, SubsetWhenSecondHasLargerCountShouldReturnTrue) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 2}});

    ASSERT_TRUE(stockA.subsetOf(stockB));
}

TEST(TestStock, SubsetWhenWhenSecondEmptyShouldReturnFalse) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    ASSERT_TRUE(!stockA.subsetOf(stockB));
}

TEST(TestStock, SubsetWhenDifferentCountsShouldReturnFalse) {
    Stock stockA({{Resource::PERSON, 2}});
    Stock stockB({{Resource::PERSON, 1}});

    ASSERT_TRUE(!stockA.subsetOf(stockB));
}

TEST(TestStock, SubsetWhenDifferentTypesShouldReturnFalse) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::ELECTRICITY, 1}});

    ASSERT_TRUE(!stockA.subsetOf(stockB));
}
