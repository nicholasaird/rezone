#include <string>

#include "gtest/gtest.h"

#include "Resource.h"
#include "Zone.h"
#include "ResourceException.h"
#include "Stock.h"
#include "StockPair.h"

Zone createSimpleZone() {
    StockPair recipe(Stock({{Resource::ELECTRICITY, 1}}), Stock({{Resource::PERSON, 1}}));

    return Zone(recipe);
}

void provideAll(Zone& zone) {
    zone.provide(zone.getUnprovided());
}

void unprovideAll(Zone& zone) {
    zone.unprovide(zone.getProvided());
}

void takeAll(Zone& zone) {
    zone.take(zone.getUntaken());
}

void untakeAll(Zone& zone) {
    zone.untake(zone.getTaken());
}

TEST(TestZone, DefaultShouldHaveNothingProvided) {
    Zone zone = createSimpleZone();

    ASSERT_EQ(Stock(), zone.getProvided());
}

TEST(TestZone, DefaultUnprovidedShouldBeSameAsRecipeInput) {
    Zone zone = createSimpleZone();

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getUnprovided());
}

TEST(TestZone, DefaultShouldHaveNothingTaken) {
    Zone zone = createSimpleZone();

    zone.updateProduction();

    ASSERT_EQ(Stock(), zone.getTaken());
}

TEST(TestZone, WhenDefaultHasNoInputShouldHaveTakeableSameAsRecipeOutput) {
    StockPair recipe(Stock(), Stock({{Resource::PERSON, 1}}));
    Zone zone(recipe);

    zone.updateProduction();

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getUntaken());
}

TEST(TestZone, WhenDefaultHasInputsShouldHaveNothingTakeable) {
    Zone zone = createSimpleZone();

    zone.updateProduction();

    ASSERT_EQ(Stock(), zone.getUntaken());
}

TEST(TestZone, WhenProvidedShouldLowerInputUnprovided) {
    Zone zone = createSimpleZone();

    provideAll(zone);

    ASSERT_EQ(Stock(), zone.getUnprovided());
}

TEST(TestZone, WhenPartiallyProvidedShouldLowerInputUnprovided) {
    StockPair recipe(Stock({{Resource::ELECTRICITY, 2}}), Stock({{Resource::PERSON, 1}}));
    Zone zone(recipe);

    zone.provide(Stock({{Resource::ELECTRICITY, 1}}));

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getUnprovided());
}

TEST(TestZone, DefaultCapsShouldBeSameAsRecipe) {
    Zone zone = createSimpleZone();

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenNothingTakenShouldNotIncreaseCaps) {
    Zone zone = createSimpleZone();

    Stock relief({{Resource::PERSON, 1}});
    zone.updateCap(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenCanIncreaseCapsAndReliefShouldIncreaseCaps) {
    Zone zone = createSimpleZone();

    provideAll(zone);
    zone.updateProduction();

    takeAll(zone);

    Stock relief({{Resource::PERSON, 1}});
    zone.updateCap(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 2}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), zone.getOutputCap());
}

TEST(TestZone, WhenCanIncreaseCapsButNoReliefShouldNotIncreaseCaps) {
    Zone zone = createSimpleZone();

    provideAll(zone);
    zone.updateProduction();

    takeAll(zone);

    Stock relief;
    zone.updateCap(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenTakenTooLowShouldDecreaseCaps) {
    Zone zone = createSimpleZone();

    provideAll(zone);
    zone.updateProduction();

    takeAll(zone);

    Stock relief({{Resource::PERSON, 1}});
    zone.updateCap(relief);

    untakeAll(zone);
    zone.updateCap(relief);

    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getInputCap());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), zone.getOutputCap());
}

TEST(TestZone, WhenTakeButNothingAvailableShouldThrow) {
    Zone zone = createSimpleZone();

    Stock untakeableStock({{Resource::PERSON, 1}});
    ASSERT_THROW(zone.take(untakeableStock), ResourceException);
}

TEST(TestZone, WhenProvideButNothingUnprovidedShouldThrow) {
    StockPair emptyRecipe;
    Zone zone(emptyRecipe);

    Stock unprovideable({{Resource::ELECTRICITY, 1}});
    ASSERT_THROW(zone.provide(unprovideable), ResourceException);
}

TEST(TestZone, WhenProvideButNothingUnprovidedShouldThrow2) {
    Zone zone = createSimpleZone();

    provideAll(zone);

    Stock unprovideable({{Resource::ELECTRICITY, 1}});
    ASSERT_THROW(zone.provide(unprovideable), ResourceException);
}

TEST(TestZone, Name) {
    StockPair emptyRecipe;
    Zone zone("ZoneABC", emptyRecipe);

    ASSERT_EQ("ZoneABC", zone.getName());
}

TEST(TestZone, WhenUnprovideShouldIncreaseUnprovided) {
    Zone zone = createSimpleZone();

    zone.provide(Stock({{Resource::ELECTRICITY, 1}}));
    zone.unprovide(Stock({{Resource::ELECTRICITY, 1}}));

    ASSERT_EQ(Stock(), zone.getProvided());
    ASSERT_EQ(Stock({{Resource::ELECTRICITY, 1}}), zone.getUnprovided());
}
