#include "gtest/gtest.h"

#include "Resource.h"
#include "Zone.h"
#include "Stock.h"

TEST(TestZone, WhenInitializedShouldHaveNoInputMet) {
    Zone zone;

    ASSERT_EQ(Stock(), zone.getInputMet());
}
