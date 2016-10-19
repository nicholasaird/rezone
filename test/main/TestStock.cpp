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

TEST(TestStock, TimesEqualWhenEmptyAndByZeroShouldMakeEmpty) {
    Stock stockA;

    stockA *= 0;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesEqualWhenEmptyShouldMakeEmpty) {
    Stock stockA;

    stockA *= 1;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesEqualWhenEmptyShouldMakeEmpty2) {
    Stock stockA;

    stockA *= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesEqualWhenByZeroShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 0;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesEqualWhenByOneShouldMakeSame) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, TimesEqualWhenByTwoShouldDouble) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA *= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), stockA);
}

TEST(TestStock, DivEqualWhenEmptyAndShouldMakeEmpty) {
    Stock stockA;

    stockA /= 1;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, DivEqualWhenEmptyAndShouldMakeEmpty2) {
    Stock stockA;

    stockA /= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, DivEqualWhenByOneShouldMakeSame) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA /= 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, DivEqualWhenSmallCountAndByTwoShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA /= 2;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, DivEqualWhenByTwoShouldMakeHalf) {
    Stock stockA({{Resource::PERSON, 2}});

    stockA /= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, DivEqualWhenByTwoShouldMakeHalfRoundedDown) {
    Stock stockA({{Resource::PERSON, 3}});

    stockA /= 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, MinusEqualWhenBothEmptyShouldMakeEmpty) {
    Stock stockA;
    Stock stockB;

    stockA -= stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, MinusEqualWhenSecondEmptyShouldMakeSame) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    stockA -= stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, MinusEqualWhenSameCountsShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    stockA -= stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, MinusEqualWhenFirstHasLargerCountShouldReturnNonEmpty) {
    Stock stockA({{Resource::PERSON, 2}});
    Stock stockB({{Resource::PERSON, 1}});

    stockA -= stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, MinusEqualWhenWithItselfShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 2}});

    stockA -= stockA;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, PlusEmptyWhenBothEmptyShouldMakeEmpty) {
    Stock stockA;
    Stock stockB;

    stockA += stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, PlusEqualWhenSecondEmptyShouldMakeFirst) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, PlusEqualWhenFirstEmptyShouldMakeSecond) {
    Stock stockA;
    Stock stockB({{Resource::PERSON, 1}});

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), stockA);
}

TEST(TestStock, PlusEqualWhenDifferentCountsShouldMakeSum) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 2}});

    stockA += stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 3}}), stockA);
}

TEST(TestStock, PlusEqualWhenDifferentResourcesShouldMakeSum) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::ELECTRICITY, 1}});

    stockA += stockB;

    ASSERT_EQ(
        Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}}),
        stockA
    );
}

TEST(TestStock, PlusEqualWhenWithNegativeEquivalentShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, -1}});

    stockA += stockB;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, PlusEqualWhenWithItsNegativeShouldMakeEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    stockA += -stockA;

    ASSERT_EQ(Stock(), stockA);
}

TEST(TestStock, TimesWhenEmptyByZeroShouldReturnEmpty) {
    Stock stockA;

    Stock result = stockA * 0;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, TimesWhenEmptyShouldReturnEmpty) {
    Stock stockA;

    Stock result = stockA * 1;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, TimesWhenEmptyShouldReturnEmpty2) {
    Stock stockA;

    Stock result = stockA * 2;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, TimesWhenByZeroShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 0;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, TimesWhenByOneShouldReturnSame) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, TimesWhenMultTwoShouldReturnDouble) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA * 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), result);
}

TEST(TestStock, TimesWhenMultTwoShouldReturnDouble2) {
    Stock stockA({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}});

    Stock result = stockA * 2;

    ASSERT_EQ(
        Stock({{Resource::PERSON, 2}, {Resource::ELECTRICITY, 2}}),
        result
    );
}

TEST(TestStock, DivWhenEmptyShouldReturnEmpty) {
    Stock stockA;

    Stock result = stockA / 1;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, DivWhenEmptyShouldReturnEmpty2) {
    Stock stockA;

    Stock result = stockA / 2;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, DivWhenDivByOneShouldReturnSame) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA / 1;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, DivWhenSmallShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA / 2;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, DivShouldReturnHalf) {
    Stock stockA({{Resource::PERSON, 2}});

    Stock result = stockA / 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, DivShouldReturnHalfRoundedDown) {
    Stock stockA({{Resource::PERSON, 3}});

    Stock result = stockA / 2;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, PlusWhenBothEmptyShouldReturnEmpty) {
    Stock stockA;
    Stock stockB;

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, PlusWhenSecondEmptyShouldReturnFirst) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB;

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, PlusWhenEqualShouldReturnDouble) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, 1}});

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), result);
}

TEST(TestStock, PlusWhenDifferentResourcesShouldAdd) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::ELECTRICITY, 1}});

    Stock result = stockA + stockB;

    ASSERT_EQ(
        Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}}),
        result
    );
}

TEST(TestStock, PlusWhenWithNegativeCountShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});
    Stock stockB({{Resource::PERSON, -1}});

    Stock result = stockA + stockB;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, PlusWhenWithNegativeOfItselfShouldReturnEmpty) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = stockA + -stockA;

    ASSERT_EQ(Stock(), result);
}

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

TEST(TestStock, UnaryMinusWhenEmptyShouldReturnEmpty) {
    Stock stockA;

    Stock result = -stockA;

    ASSERT_EQ(Stock(), result);
}

TEST(TestStock, UnaryMinusShouldReturnNegative) {
    Stock stockA({{Resource::PERSON, 1}});

    Stock result = -stockA;

    ASSERT_EQ(Stock({{Resource::PERSON, -1}}), result);
}

TEST(TestStock, UnaryMinusWhenNegativeShouldReturnPositive) {
    Stock stockA({{Resource::PERSON, -1}});

    Stock result = -stockA;

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), result);
}

TEST(TestStock, TimesItContainsWhenBothEmptyShouldReturnZero) {
    Stock stockA;

    int result = stockA.timesItContains(Stock());

    ASSERT_EQ(0, result);
}

TEST(TestStock, TimesItContainsWhenFirstEmptyShouldReturnZero) {
    Stock stockA;

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(0, result);
}

TEST(TestStock, TimesItContainsWhenFirstNotEnoughShouldReturnZero) {
    Stock stockA({{Resource::PERSON, 1}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 2}}));

    ASSERT_EQ(0, result);
}

TEST(TestStock, TimesItContainsWhenSameShouldBeOne) {
    Stock stockA({{Resource::PERSON, 1}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(1, result);
}

TEST(TestStock, TimesItContainsWhenDoubleShouldBeTwo) {
    Stock stockA({{Resource::PERSON, 2}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(2, result);
}

TEST(TestStock, TimesItContainsWhenDifferentResourceShouldBeZero) {
    Stock stockA({{Resource::PERSON, 1}});

    int result = stockA.timesItContains(Stock({{Resource::ELECTRICITY, 1}}));

    ASSERT_EQ(0, result);
}

TEST(TestStock, TimesItContainsWhenExtraResourceShouldHaveNoEffect) {
    Stock stockA({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(1, result);
}

TEST(TestStock, TimesItContainsWhenComplexStocks) {
    Stock stockA({{Resource::PERSON, 4}, {Resource::ELECTRICITY, 5}});

    int result = stockA.timesItContains(Stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 3}}));

    ASSERT_EQ(1, result);
}
