#include <memory>  // shared_ptr

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mocks/MockNeeds.h"
#include "Needs.h"
#include "Leveler.h"
#include "Resource.h"
#include "Stock.h"
#include "StockPair.h"

using ::testing::Return;
using ::testing::_;

StockPair hugeStockPair(Stock({{Resource::PERSON, 1000000}}), Stock());
StockPair emptyStockPair;

TEST(TestLeveler, WhenNeedsNotMetShouldNotLevelUp) {
    std::shared_ptr<MockNeeds> mockNeeds = std::make_shared<MockNeeds>();
    std::shared_ptr<Needs> needs = mockNeeds;
    EXPECT_CALL(*mockNeeds, required(_))
        .WillRepeatedly(Return(StockPair(Stock({{Resource::PERSON, 1000000}}), Stock())));

    Leveler leveler(needs);

    leveler.update();

    ASSERT_EQ(0, leveler.getLevel());
}

TEST(TestLeveler, WhenNeedsMetShouldLevelUp) {
    std::shared_ptr<MockNeeds> mockNeeds = std::make_shared<MockNeeds>();
    std::shared_ptr<Needs> needs = mockNeeds;
    EXPECT_CALL(*mockNeeds, required(_))
        .WillRepeatedly(Return(emptyStockPair));

    Leveler leveler(needs);

    leveler.update();

    ASSERT_EQ(1, leveler.getLevel());
}
