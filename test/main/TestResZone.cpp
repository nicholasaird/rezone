#include "gtest/gtest.h"

#include "Resource.hpp"
#include "ResZone.hpp"

TEST(TestResZone, InitialPopShouldBeZero) {
    ResZone resZone;

    ASSERT_EQ(0, resZone.getNumProduced(Resource::PERSON));
}
