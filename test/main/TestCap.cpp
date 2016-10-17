#include "gtest/gtest.h"

#include "Cap.h"
#include "Resource.h"
#include "Stock.h"
#include "StockPair.h"


TEST(TestCap, WhenNoReliefShouldNoIncreaseCaps) {
    StockPair simpleRecipe(Stock(), Stock({{Resource::PERSON, 1}}));
    Cap cap(simpleRecipe);

    Stock noRelief;
    cap.update(noRelief);

    ASSERT_EQ(Stock(), cap.getInput());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), cap.getOutput());
}
