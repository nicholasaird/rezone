#include "gtest/gtest.h"

#include "Resource.h"
#include "Zone.h"
#include "Stock.h"
#include "StockPair.h"

void meetAllNeeds(Zone zone) {
    zone.supplyInput(zone.getInputAvailable());
    zone.takeOutput(zone.getOutputAvailable());
}

void meetNoNeeds(Zone zone) {
    zone.cancelInput(zone.getInputMet());
    zone.cancelInput(zone.getOutputMet());
}

TEST(TestZone, WhenInitializedShouldHaveNoInputMet) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    ASSERT_EQ(Stock(), zone.getInputMet());
}

TEST(TestZone, WhenInitializedShouldHaveInputAvailableSameAsRecipe) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputAvailable());
}

TEST(TestZone, WhenSupplyInputShouldLowerInputAvailable) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.supplyInput(Stock({{Resource::ELECTRICITY, 1}}));

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 0}}), zone.getInputAvailable());
}

TEST(TestZone, WhenSupplyPartialInputShouldLowerInputAvailable) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 2}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.supplyInput(Stock({{Resource::ELECTRICITY, 1}}));

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputAvailable());
}

TEST(TestZone, InitialCapsShouldBeSameAsRecipe) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenNoOutputSoldShouldNotIncreaseCaps) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    Stock relief({{Resource::PERSON, 1}});
    zone.update(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenOutputRequirementsMetShouldIncreaseCaps) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.supplyInput(Stock({{Resource::ELECTRICITY, 1}}));
    zone.takeOutput(Stock({{Resource::PERSON, 1}}));
    Stock relief({{Resource::PERSON, 1}});
    zone.update(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 2}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), zone.getOutputCap());
}

TEST(TestZone, WhenCanIncreaseCapsButNoReliefShouldNotIncreaseCaps) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.supplyInput(Stock({{Resource::ELECTRICITY, 1}}));
    zone.takeOutput(Stock({{Resource::PERSON, 1}}));
    Stock relief;
    zone.update(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenOutputTooLowShouldDecreaseCaps) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.supplyInput(Stock({{Resource::ELECTRICITY, 1}}));
    zone.takeOutput(Stock({{Resource::PERSON, 1}}));
    Stock relief({{Resource::PERSON, 1}});
    zone.update(relief);

    zone.cancelOutput(Stock({{Resource::PERSON, 1}}));
    zone.update(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}
