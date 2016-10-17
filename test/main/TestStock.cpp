#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStock, EmptyStockShouldHaveAll0) {
    Stock stock;

    ASSERT_EQ(0, stock.get(Resource::PERSON));
    ASSERT_EQ(0, stock.get(Resource::COM_PRODUCT));
    ASSERT_EQ(0, stock.get(Resource::IND_PRODUCT));
}

TEST(TestStock, SetOnePerson) {
    Stock stock;

    stock.set(Resource::PERSON, 1);

    ASSERT_EQ(1, stock.get(Resource::PERSON));
}

TEST(TestStock, SetOneComProduct) {
    Stock stock;

    stock.set(Resource::COM_PRODUCT, 1);

    ASSERT_EQ(1, stock.get(Resource::COM_PRODUCT));
}

TEST(TestStock, SetOneIndProduct) {
    Stock stock;

    stock.set(Resource::IND_PRODUCT, 1);

    ASSERT_EQ(1, stock.get(Resource::IND_PRODUCT));
}

TEST(TestStock, SetManyPerson) {
    Stock stock;

    stock.set(Resource::PERSON, 10);

    ASSERT_EQ(10, stock.get(Resource::PERSON));
}

TEST(TestStock, SetVarious) {
    Stock stock;

    stock.set(Resource::PERSON, 1);
    stock.set(Resource::COM_PRODUCT, 2);
    stock.set(Resource::IND_PRODUCT, 3);

    ASSERT_EQ(1, stock.get(Resource::PERSON));
    ASSERT_EQ(2, stock.get(Resource::COM_PRODUCT));
    ASSERT_EQ(3, stock.get(Resource::IND_PRODUCT));
}

TEST(TestStock, SettingShouldAddOnlyThatResource) {
    Stock stock;

    stock.set(Resource::PERSON, 1);

    ASSERT_EQ(1, stock.get(Resource::PERSON));
    ASSERT_EQ(0, stock.get(Resource::COM_PRODUCT));
    ASSERT_EQ(0, stock.get(Resource::IND_PRODUCT));
}

TEST(TestStock, StockShouldHaveNewestCount) {
    Stock stock;

    stock.set(Resource::PERSON, 1);
    stock.set(Resource::PERSON, 2);

    Stock expected({{Resource::PERSON, 2}});

    ASSERT_EQ(expected, stock);
}

TEST(TestStock, WhenEmptyShouldNotIterate) {
    Stock stock;

    int loops = 0;
    for(auto pair : stock) {
        loops++;
    }

    ASSERT_EQ(0, loops);
}

TEST(TestStock, WhenEmptyShouldNotIterate2) {
    Stock stock({{Resource::PERSON, 0}});

    int loops = 0;
    for(auto pair : stock) {
        loops++;
    }

    ASSERT_EQ(0, loops);
}

TEST(TestStock, WhenOneTypeShouldIterateOnce) {
    Stock stock;
    stock.set(Resource::PERSON, 1);

    int loops = 0;
    for(auto pair : stock) {
        loops++;
    }

    ASSERT_EQ(1, loops);
}

TEST(TestStock, WhenTwoTypesShouldIterateTwice) {
    Stock stock;
    stock.set(Resource::PERSON, 1);
    stock.set(Resource::IND_PRODUCT, 1);

    int loops = 0;
    for(auto pair : stock) {
        loops++;
    }

    ASSERT_EQ(2, loops);
}

TEST(TestStock, WhenOneTypeAndChangedCountShouldIterateOnce) {
    Stock stock;
    stock.set(Resource::PERSON, 1);
    stock.set(Resource::PERSON, 2);

    int loops = 0;
    for(auto pair : stock) {
        loops++;
    }

    ASSERT_EQ(1, loops);
}

TEST(TestStock, IterationShouldFindSingleResource) {
    Stock stock;
    stock.set(Resource::PERSON, 1);

    bool found = false;
    for(auto pair : stock) {
        if(pair.first == Resource::PERSON) {
            found = true;
        }
    }

    ASSERT_TRUE(found);
}

TEST(TestStock, IterationShouldFindTwoResources) {
    Stock stock;
    stock.set(Resource::PERSON, 1);
    stock.set(Resource::IND_PRODUCT, 1);

    bool foundPerson = false;
    bool foundInd = false;
    for(auto pair : stock) {
        if(pair.first == Resource::PERSON) {
            foundPerson = true;
        }
        else if(pair.first == Resource::IND_PRODUCT) {
            foundInd = true;
        }
    }

    ASSERT_TRUE(foundPerson && foundInd);
}

TEST(TestStock, IterationShouldProvideCorrectCount) {
    Stock stock;
    stock.set(Resource::PERSON, 1);

    bool correctCount = false;
    for(auto pair : stock) {
        if(pair.first == Resource::PERSON && pair.second == 1) {
            correctCount = true;
        }
    }

    ASSERT_TRUE(correctCount);
}

TEST(TestStock, EqualEmptyStocks) {
    Stock stockA;
    Stock stockB;

    ASSERT_EQ(stockA, stockB);
}

TEST(TestStock, EqualEmptyStocks2) {
    Stock stockA({{Resource::PERSON, 0}});
    Stock stockB;

    ASSERT_EQ(stockA, stockB);
}

TEST(TestStock, EqualSimpleStocks) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    ASSERT_EQ(stockA, stockB);
}

TEST(TestStock, EmptyAndNonEmptyShouldBeNonEqual) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    ASSERT_NE(stockA, stockB);
}

TEST(TestStock, DifferentTypesShouldBeNonEqual) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::IND_PRODUCT, 1}});

    ASSERT_NE(stockA, stockB);
}

TEST(TestStock, DifferentCountsShouldBeNonEqual) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 2}});

    ASSERT_NE(stockA, stockB);
}

TEST(TestStock, WhenBothEmptySubsetTrue) {
    Stock stockA;
    Stock stockB;

    ASSERT_TRUE(stockA.subsetOf(stockB));
}

TEST(TestStock, WhenNonEmptySubsetTrue) {
    Stock stockA;
    Stock stockB({{Resource::PERSON, 1}});

    ASSERT_TRUE(stockA.subsetOf(stockB));
}

TEST(TestStock, WhenNonEmptySubsetFalse) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    ASSERT_TRUE(!stockA.subsetOf(stockB));
}

TEST(TestStock, WhenBothEmptySupersetTrue) {
    Stock stockA;
    Stock stockB;

    ASSERT_TRUE(stockA.supersetOf(stockB));
}

TEST(TestStock, WhenNonEmptySupersetTrue) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    ASSERT_TRUE(stockA.supersetOf(stockB));
}

TEST(TestStock, WhenNonEmptySupersetFalse) {
    Stock stockA;
    Stock stockB({{Resource::PERSON, 1}});

    ASSERT_TRUE(!stockA.supersetOf(stockB));
}

TEST(TestStock, WhenEmptyMultEqualShouldReturnEmpty) {
    Stock stockA;

    stockA *= 1;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, WhenEmptyMultEqualShouldReturnEmpty2) {
    Stock stockA;

    stockA *= 2;

    ASSERT_EQ(Stock(), stockA);
}
