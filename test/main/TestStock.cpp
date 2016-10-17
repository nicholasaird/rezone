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

TEST(TestStock, WhenEmptyMultEqualShouldNotChange) {
    Stock stockA;

    stockA *= 1;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, WhenEmptyMultEqualShouldNotChange2) {
    Stock stockA;

    stockA *= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, WhenEmptyMultEqual0ShouldNotChange) {
    Stock stockA;

    stockA *= 0;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, WhenMultEqual0ShouldBeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 0;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, WhenMultEqual1ShouldNotChange) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, WhenMultEqual2ShouldBeDouble) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), stockA);
}

TEST(TestStock, EmptyDivEqualOneShouldNotChange) {
    Stock stockA;

    stockA /= 1;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, EmptyDivEqualTwoShouldNotChange) {
    Stock stockA;

    stockA /= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, DivEqualOneShouldNotChange) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA /= 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, StockOneDivEqualTwoShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA /= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, DivEqualTwoShouldMakeHalf) {
    Stock stockA({{Resource::PERSON, 2}});

    stockA /= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, DivEqualTwoShouldMakeHalfRoundedDown) {
    Stock stockA({{Resource::PERSON, 3}});

    stockA /= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, WhenEmptyMinusEqualEmptyShouldBeEmpty) {
    Stock stockA;
    Stock stockB;

    stockA -= stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, WhenNonEmptyMinusEqualEmptyShouldNotChange) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    stockA -= stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, MinusEqualThatShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    stockA -= stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, MinusEqualThatShouldReturnNonEmpty) {
    Stock stockA({{Resource::PERSON, 2}});
    Stock stockB({{Resource::PERSON, 1}});

    stockA -= stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, MinusEqualItselfShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 2}});

    stockA -= stockA;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, EmptyPlusEqualEmptyShouldReturnEmpty) {
    Stock stockA;
    Stock stockB;

    stockA += stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, NonEmptyPlusEqualEmptyShouldNotChange) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, EmptyPlusEqualNonEmptyShouldMakeNonEmpty) {
    Stock stockA;
    Stock stockB({{Resource::PERSON, 1}});

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, APlusEqualBShouldMakeSum) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 2}});

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 3}}), stockA);
}

TEST(TestStock, APlusEqualBShouldMakeSum2) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::ELECTRICITY, 1}});

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}}), stockA);
}

TEST(TestStock, APlusEqualMinusAShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, -1}});

    stockA += stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, APlusEqualMinusAShouldMakeEmpty2) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA += -stockA;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, EmptyTimesZeroReturnsEmpty) {
    Stock stockA;

    Stock result = stockA * 0;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, EmptyTimesOneReturnsEmpty) {
    Stock stockA;

    Stock result = stockA * 1;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, EmptyTimesTwoReturnsEmpty) {
    Stock stockA;

    Stock result = stockA * 2;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, ATimesZeroReturnsEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 0;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, ATimesOneReturnsA) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, ATimesTwoReturnsDouble) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), result);
}

TEST(TestStock, ATimesTwoReturnsDouble2) {
    Stock stockA({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}});

    Stock result = stockA * 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}, {Resource::ELECTRICITY, 2}}), result);
}

TEST(TestStock, EmptyAddEmptyShouldReturnEmpty) {
    Stock stockA;
    Stock stockB;

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, NonEmptyAddEmptyShouldReturnFirst) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, APlusBSameResources) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), result);
}

TEST(TestStock, APlusBDifferentResources) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::ELECTRICITY, 1}});

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}}), result);
}

TEST(TestStock, APlusMinusAShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, -1}});

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, APlusMinusAShouldReturnEmpty2) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA + -stockA;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, EmptyMinusEmptyShouldReturnEmpty) {
    Stock stockA;
    Stock stockB;

    Stock result = stockA - stockB;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, NonEmptyMinusEmptyShouldReturnFirst) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    Stock result = stockA - stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, NonEmptyMinusSameNonEmptyShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    Stock result = stockA - stockB;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, NonEmptyMinusDifferentNonEmptyShouldReturnNonEmpty) {
    Stock stockA({{Resource::PERSON, 2}});
    Stock stockB({{Resource::PERSON, 1}});

    Stock result = stockA - stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, EmptyMinusShouldReturnEmpty) {
    Stock stockA;

    Stock result = -stockA;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, NonEmptyMinusShouldReturnNegative) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = -stockA;

    ASSERT_EQ(Stock({{Resource::PERSON, -1}}), result);
}

TEST(TestStock, MinusOfNegativeShouldReturnPositive) {
    Stock stockA({{Resource::PERSON, -1}});

    Stock result = -stockA;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}
