#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, WhenBothEmptyShouldBeEqual) {
    Stock stockA;
    Stock stockB;

    ASSERT_TRUE(stockA == stockB);
}

TEST(TestStock, WhenBothEmptyShouldBeEqual2) {
    Stock stockA({{Resource::PERSON, 0}});
    Stock stockB;

    ASSERT_TRUE(stockA == stockB);
}

TEST(TestStock, WhenSameCountsShouldBeEqual) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    ASSERT_TRUE(stockA == stockB);
}
