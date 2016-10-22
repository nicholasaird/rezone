#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, MinusWhenBothEmptyShouldReturnEmpty) {
    Stock stockA;
    Stock stockB;

    Stock result = stockA - stockB;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, MinusWhenSecondEmptyShouldlReturnFirst) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    Stock result = stockA - stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, MinusWhenSameCountsShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    Stock result = stockA - stockB;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, MinusWhenFirstEmptyShouldReturnNonEmpty) {
    Stock stockA({{Resource::PERSON, 2}});
    Stock stockB({{Resource::PERSON, 1}});

    Stock result = stockA - stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, MinusWhenDifferentResourcesShouldReturnNegativeCount) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::ELECTRICITY, 1}});

    Stock result = stockA - stockB;

    ASSERT_EQ(
        Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, -1}}),
        result
    );
}
