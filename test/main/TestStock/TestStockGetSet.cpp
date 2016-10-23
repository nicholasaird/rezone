#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStockSetGet, SetGet) {
    Stock stock;

    stock.set(Resource::PERSON, 1);

    ASSERT_EQ(1, stock.get(Resource::PERSON));
}

TEST(TestStockSetGet, SetGet2) {
    Stock stock;

    stock.set(Resource::PERSON, 2);

    ASSERT_EQ(2, stock.get(Resource::PERSON));
}

TEST(TestStockSetGet, SetGetWhenModified) {
    Stock stock;

    stock.set(Resource::PERSON, 1);
    stock.set(Resource::PERSON, 2);

    ASSERT_EQ(2, stock.get(Resource::PERSON));
}

TEST(TestStockSetGet, SetGetWhenEmpty) {
    Stock stock;

    ASSERT_EQ(0, stock.get(Resource::PERSON));
}

TEST(TestStockSetGet, SetGetWhenOtherResource) {
    Stock stock;

    stock.set(Resource::PERSON, 1);

    ASSERT_EQ(0, stock.get(Resource::ELECTRICITY));
}

TEST(TestStockSetGet, SetGetWhenManyResources) {
    Stock stock;

    stock.set(Resource::PERSON, 1);
    stock.set(Resource::ELECTRICITY, 2);

    ASSERT_EQ(1, stock.get(Resource::PERSON));
    ASSERT_EQ(2, stock.get(Resource::ELECTRICITY));
}
