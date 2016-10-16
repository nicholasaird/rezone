#include "gtest/gtest.h"

#include "Resource.hpp"
#include "ResZone.hpp"
#include "Stock.hpp"

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

TEST(TestResZone, Level0ShouldNotGrowWhenNotElectrified) {
    ResZone resZone;

    resZone.updateLevel();

    Stock result = resZone.getProductionTotal();
    Stock expected({{Resource::PERSON, 0}});

    ASSERT_EQ(expected, result);
}

TEST(TestResZone, Level0ShouldGrowWhenNeedsAreMet) {
    ResZone resZone;

    resZone.setConnectedTo(Utility::ELECTRICITY, true);
    resZone.updateLevel();

    Stock result = resZone.getProductionTotal();
    Stock expected({{Resource::PERSON, 1}});

    ASSERT_EQ(expected, result);
}
