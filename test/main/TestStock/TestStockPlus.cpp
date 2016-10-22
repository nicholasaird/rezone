#include "gtest/gtest.h"

#include "Stock.h"

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
