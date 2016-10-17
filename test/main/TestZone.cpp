#include "gtest/gtest.h"

#include "Resource.h"
#include "Zone.h"
#include "Stock.h"
#include "StockPair.h"

TEST(TestZone, WhenInitializedShouldHaveNoInputMet) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    ASSERT_EQ(Stock(), zone.getInputMet());
}
