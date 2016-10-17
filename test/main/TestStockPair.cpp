#include "gtest/gtest.h"

#include "Resource.h"
#include "StockPair.h"

TEST(TestStockPair, EmptySubsetTrue) {
    StockPair pairA;
    StockPair pairB;

    ASSERT_TRUE(pairA.subsetOf(pairB));
}

TEST(TestStockPair, NonEmptySubsetTrue) {
    StockPair pairA;
    StockPair pairB(Stock({{Resource::PERSON, 1}}), Stock());

    ASSERT_TRUE(pairA.subsetOf(pairB));
}

TEST(TestStockPair, NonEmptySubsetFalse) {
    StockPair pairA(Stock({{Resource::PERSON, 1}}), Stock());
    StockPair pairB;

    ASSERT_TRUE(!pairA.subsetOf(pairB));
}

TEST(TestStockPair, EmptySupersetTrue) {
    StockPair pairA;
    StockPair pairB;

    ASSERT_TRUE(pairA.supersetOf(pairB));
}

TEST(TestStockPair, NonEmptySupersetTrue) {
    StockPair pairA(Stock({{Resource::PERSON, 1}}), Stock());
    StockPair pairB;

    ASSERT_TRUE(pairA.supersetOf(pairB));
}

TEST(TestStockPair, NonEmptySupersetFalse) {
    StockPair pairA;
    StockPair pairB(Stock({{Resource::PERSON, 1}}), Stock());

    ASSERT_TRUE(!pairA.supersetOf(pairB));
}

TEST(TestStockPair, EmptyEqualTrue) {
    StockPair pairA;
    StockPair pairB;

    ASSERT_EQ(pairA, pairB);
}

TEST(TestStockPair, NonEmptyEqualTrue) {
    StockPair pairA(Stock({{Resource::PERSON, 1}}), Stock());
    StockPair pairB(Stock({{Resource::PERSON, 1}}), Stock());

    ASSERT_EQ(pairA, pairB);
}

TEST(TestStockPair, NonEmptyEqualFalse) {
    StockPair pairA;
    StockPair pairB(Stock({{Resource::PERSON, 1}}), Stock());

    ASSERT_NE(pairA, pairB);
}

TEST(TestStockPair, NonEmptyEqualFalse2) {
    StockPair pairA(Stock({{Resource::IND_PRODUCT, 1}}), Stock());
    StockPair pairB(Stock({{Resource::PERSON, 1}}), Stock());

    ASSERT_NE(pairA, pairB);
}

TEST(TestStockPair, NonEmptyEqualFalse3) {
    StockPair pairA(Stock(), Stock({{Resource::PERSON, 1}}));
    StockPair pairB(Stock({{Resource::PERSON, 1}}), Stock());

    ASSERT_NE(pairA, pairB);
}
