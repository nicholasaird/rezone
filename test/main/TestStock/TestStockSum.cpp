#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, SumWhenEmptyShouldReturnZero) {
    Stock stockA;

    int result = stockA.sum();

    ASSERT_EQ(0, result);
}

TEST(TestStock, SumWhenCountOfOneShouldReturnOne) {
    Stock stockA({{Resource::PERSON, 1}});

    int result = stockA.sum();

    ASSERT_EQ(1, result);
}

TEST(TestStock, SumWhenCountOfTwoShouldReturnTwo) {
    Stock stockA({{Resource::PERSON, 2}});

    int result = stockA.sum();

    ASSERT_EQ(2, result);
}

TEST(TestStock, SumWhenCountIsLargeShouldReturnLarge) {
    Stock stockA({{Resource::PERSON, 2}});

    int result = stockA.sum();

    ASSERT_EQ(2, result);
}

TEST(TestStock, SumWhenDifferentResourcesShouldAddThem) {
    Stock stockA({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}});

    int result = stockA.sum();

    ASSERT_EQ(2, result);
}

TEST(TestStock, SumWhenDifferentResourcesShouldAddThem2) {
    Stock stockA({{Resource::PERSON, 2}, {Resource::ELECTRICITY, 5}});

    int result = stockA.sum();

    ASSERT_EQ(7, result);
}

TEST(TestStock, SumWhenDifferentResourcesShouldAddThem3) {
    Stock stockA({
        {Resource::PERSON, 1},
        {Resource::ELECTRICITY, 1},
        {Resource::IND_PRODUCT, 1}
    });

    int result = stockA.sum();

    ASSERT_EQ(3, result);
}
