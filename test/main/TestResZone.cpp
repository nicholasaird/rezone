#include "gtest/gtest.h"

#include "Resource.h"
#include "ResZone.h"
#include "Stock.h"

TEST(TestResZone, InitialPopProducedShouldBeZero) {
    ResZone resZone;

    Stock result = resZone.getProductionTotal();
    Stock expected({{Resource::PERSON, 0}});

    ASSERT_EQ(expected, result);
}

TEST(TestResZone, InitialPopAvailableShouldBeZero) {
    ResZone resZone;

    Stock result = resZone.getProductionUnused();
    Stock expected({{Resource::PERSON, 0}});

    ASSERT_EQ(expected, result);
}
