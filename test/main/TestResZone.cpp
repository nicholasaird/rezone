#include "gtest/gtest.h"

#include "Resource.hpp"
#include "ResZone.hpp"

TEST(TestResZone, InitialPopProducedShouldBeZero) {
    ResZone resZone;

    ASSERT_EQ(0, resZone.getProductionTotal(Resource::PERSON));
}

TEST(TestResZone, InitialPopAvailableShouldBeZero) {
    ResZone resZone;

    ASSERT_EQ(0, resZone.getProductionUnused(Resource::PERSON));
}

TEST(TestResZone, Level0ShouldNotGrowWhenNotElectrified) {
    ResZone resZone;

    resZone.updateLevel();

    ASSERT_EQ(0, resZone.getProductionTotal(Resource::PERSON));
}

TEST(TestResZone, Level0ShouldGrowWhenNeedsAreMet) {
    ResZone resZone;

    resZone.setConnectedTo(Utility::ELECTRICITY, true);
    resZone.updateLevel();

    ASSERT_EQ(1, resZone.getLevel());
}
