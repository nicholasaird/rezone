#include <memory>  // shared_ptr

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mocks/MockNeeds.h"
#include "Leveler.h"
#include "Stock.h"
#include "StockPair.h"

using ::testing::Return;
using ::testing::_;

StockPair hugeStockPair(Stock({{Resource::PERSON, 1000000}}), Stock());

TEST(TestLeveler, WhenNeedsNotMetShouldNotLevelUp) {
    MockNeeds needs;
    EXPECT_CALL(needs, required(_))
        .WillRepeatedly(Return(hugeStockPair));

    Leveler leveler(std::make_shared<MockNeeds>());

    leveler.update();

    ASSERT_EQ(0, leveler.getLevel());
}
