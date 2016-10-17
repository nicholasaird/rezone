#include "gtest/gtest.h"

#include "Cap.h"
#include "Resource.h"
#include "Stock.h"
#include "StockPair.h"

StockPair simpleRecipe(Stock(), Stock({{Resource::PERSON, 1}}));

TEST(TestCap, WhenNoReliefShouldNoIncreaseCaps) {
    Cap cap(simpleRecipe);

    Stock noRelief;
    cap.update(noRelief);

    ASSERT_EQ(Stock(), cap.getInput());
    ASSERT_EQ(Stock(), cap.getOutput());
}
