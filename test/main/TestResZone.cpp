#include "gtest/gtest.h"

#include "Resource.hpp"
#include "ResZone.hpp"

TEST(TestResZone, InitialPopProducedShouldBeZero) {
    ResZone resZone;

    ResourceCount result = resZone.getProductionTotal();
    ResourceCount expected({{Resource::PERSON, 0}});

    ASSERT_EQ(expected, result);
}

TEST(TestResZone, InitialPopAvailableShouldBeZero) {
    ResZone resZone;

    ResourceCount result = resZone.getProductionUnused();
    ResourceCount expected({{Resource::PERSON, 0}});

    ASSERT_EQ(expected, result);
}

TEST(TestResZone, Level0ShouldNotGrowWhenNotElectrified) {
    ResZone resZone;

    resZone.updateLevel();

    ResourceCount result = resZone.getProductionTotal();
    ResourceCount expected({{Resource::PERSON, 0}});

    ASSERT_EQ(expected, result);
}

TEST(TestResZone, Level0ShouldGrowWhenNeedsAreMet) {
    ResZone resZone;

    resZone.setConnectedTo(Utility::ELECTRICITY, true);
    resZone.updateLevel();

    ResourceCount result = resZone.getProductionTotal();
    ResourceCount expected({{Resource::PERSON, 1}});

    ASSERT_EQ(expected, result);
}
