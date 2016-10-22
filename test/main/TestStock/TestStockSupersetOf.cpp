#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, SupersetWhenBothEmptyShouldReturnTrue) {
    Stock stockA;
    Stock stockB;

    ASSERT_TRUE(stockA.supersetOf(stockB));
}

TEST(TestStock, SupersetWhenSecondEmptyShouldReturnTrue) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    ASSERT_TRUE(stockA.supersetOf(stockB));
}

TEST(TestStock, SupersetWhenSecondHasLargerCountShouldReturnTrue) {
    Stock stockA({{Resource::PERSON, 2}});
    Stock stockB({{Resource::PERSON, 1}});

    ASSERT_TRUE(stockA.supersetOf(stockB));
}

TEST(TestStock, SupersetWhenFirstEmptyShouldReturnFalse) {
    Stock stockA;
    Stock stockB({{Resource::PERSON, 1}});

    ASSERT_TRUE(!stockA.supersetOf(stockB));
}

TEST(TestStock, SupersetWhenSecondHasLargerCountShouldReturnFalse) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 2}});

    ASSERT_TRUE(!stockA.supersetOf(stockB));
}

TEST(TestStock, SupersetWhenDifferentTypesShouldReturnFalse) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::ELECTRICITY, 1}});

    ASSERT_TRUE(!stockA.supersetOf(stockB));
}
