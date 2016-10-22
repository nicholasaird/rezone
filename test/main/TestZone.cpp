#include "gtest/gtest.h"

#include "Resource.h"
#include "Zone.h"
#include "ResourceException.h"
#include "Stock.h"
#include "StockPair.h"

void meetAllNeeds(Zone zone) {
    zone.provide(zone.getUnprovided());
    zone.take(zone.getUntaken());
    zone.updateProduction();
}

void meetNoNeeds(Zone zone) {
    zone.unprovide(zone.getProvided());
    zone.unprovide(zone.getTaken());
    zone.updateProduction();
}

TEST(TestZone, DefaultShouldHaveNothingProvided) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    ASSERT_EQ(Stock(), zone.getProvided());
}

TEST(TestZone, DefaultUnprovidedShouldBeSameAsRecipeInput) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getUnprovided());
}

TEST(TestZone, DefaultShouldHaveNothingTaken) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.updateProduction();

    ASSERT_EQ(Stock(), zone.getTaken());
}

TEST(TestZone, WhenDefaultHasNoInputShouldHaveAvailableSameAsRecipeOutput) {
    StockPair simpleRecipe(Stock(), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.updateProduction();

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getUntaken());
}

TEST(TestZone, WhenDefaultHasInputsShouldHaveNothingAvailable) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.updateProduction();

    ASSERT_EQ(Stock(), zone.getUntaken());
}

TEST(TestZone, WhenProvidedShouldLowerInputAvailable) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.provide(Stock({{Resource::ELECTRICITY, 1}}));

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 0}}), zone.getUnprovided());
}

TEST(TestZone, WhenPartiallyProvidedShouldLowerInputAvailable) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 2}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.provide(Stock({{Resource::ELECTRICITY, 1}}));

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getUnprovided());
}

TEST(TestZone, DefaultCapsShouldBeSameAsRecipe) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenNothingTakenShouldNotIncreaseCaps) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    Stock relief({{Resource::PERSON, 1}});
    zone.updateCap(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenCanIncreaseCapsAndReliefShouldIncreaseCaps) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.provide(Stock({{Resource::ELECTRICITY, 1}}));
    zone.updateProduction();

    zone.take(Stock({{Resource::PERSON, 1}}));
    Stock relief({{Resource::PERSON, 1}});
    zone.updateCap(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 2}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), zone.getOutputCap());
}

TEST(TestZone, WhenCanIncreaseCapsButNoReliefShouldNotIncreaseCaps) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.provide(Stock({{Resource::ELECTRICITY, 1}}));
    zone.updateProduction();

    zone.take(Stock({{Resource::PERSON, 1}}));
    Stock relief;
    zone.updateCap(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenTakenTooLowShouldDecreaseCaps) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.provide(Stock({{Resource::ELECTRICITY, 1}}));
    zone.updateProduction();

    zone.take(Stock({{Resource::PERSON, 1}}));
    Stock relief({{Resource::PERSON, 1}});
    zone.updateCap(relief);

    zone.untake(Stock({{Resource::PERSON, 1}}));
    zone.updateCap(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenTakeButNothingAvailableShouldThrow) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    ASSERT_THROW(zone.take(Stock({{Resource::PERSON, 1}})), ResourceException);
}

TEST(TestZone, WhenProvideButNothingUnprovidedShouldThrow) {
    StockPair simpleRecipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(simpleRecipe);

    zone.updateProduction();

    ASSERT_THROW(zone.provide(Stock({{Resource::PERSON, 1}})), ResourceException);
}

TEST(TestZone, Name) {
    StockPair emptyRecipe(Stock(), Stock());
    Zone zone("ZoneABC", emptyRecipe);

    ASSERT_EQ("ZoneABC", zone.getName());
}
