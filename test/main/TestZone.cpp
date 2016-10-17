#include "gtest/gtest.h"

#include "Resource.h"
#include "Zone.h"
#include "Stock.h"

TEST(TestZone, InitialPopProducedShouldBeZero) {
    Zone zone;

    Stock result = zone.getProductionTotal();
    Stock expected({{Resource::PERSON, 0}});

    ASSERT_EQ(expected, result);
}

TEST(TestZone, InitialPopAvailableShouldBeZero) {
    Zone zone;

    Stock result = zone.getProductionUnused();
    Stock expected({{Resource::PERSON, 0}});

    ASSERT_EQ(expected, result);
}
