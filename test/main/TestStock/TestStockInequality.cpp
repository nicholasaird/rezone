#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, WhenSecondEmptyShouldBeNotEqual) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    ASSERT_TRUE(stockA != stockB);
}

TEST(TestStock, WhenDifferentTypesShouldBeNotEqual) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::IND_PRODUCT, 1}});

    ASSERT_TRUE(stockA != stockB);
}

TEST(TestStock, WhenDifferentCountsShouldBeNotEqual) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 2}});

    ASSERT_TRUE(stockA != stockB);
}
