#include "gtest/gtest.h"

#include "Quota.hpp"
#include "Resource.hpp"
#include "Stock.hpp"

TEST(TestQuota, EmptyQuota) {
    Quota quota;

    ASSERT_EQ(Stock(), quota.getTotal());
    ASSERT_EQ(Stock(), quota.getMet());
    ASSERT_EQ(Stock(), quota.getUnmet());
}

TEST(TestQuota, CompletelyUnmetQuota) {
    Quota quota(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), quota.getTotal());
    ASSERT_EQ(Stock(), quota.getMet());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), quota.getUnmet());
}

TEST(TestQuota, PartiallyUnmetQuota) {
    Quota quota(
        Stock({{Resource::PERSON, 2}}),
        Stock({{Resource::PERSON, 1}})
    );

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), quota.getTotal());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), quota.getMet());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), quota.getUnmet());
}

TEST(TestQuota, PartiallyUnmetQuotaUsingSetter) {
    Quota quota(Stock({{Resource::PERSON, 2}}));
    quota.setMet(Stock({{Resource::PERSON, 1}}));

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), quota.getTotal());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), quota.getMet());
    ASSERT_EQ(Stock({{Resource::PERSON, 1}}), quota.getUnmet());
}

TEST(TestQuota, CompletelyMetQuotaUsing) {
    Quota quota(
        Stock({{Resource::PERSON, 2}}),
        Stock({{Resource::PERSON, 2}})
    );

    Stock emptyStock;
    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), quota.getTotal());
    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), quota.getMet());
    ASSERT_EQ(Stock(), quota.getUnmet());
}

TEST(TestQuota, ChangeTotalStock) {
    Quota quota;
    quota.setTotal(Stock({{Resource::PERSON, 1}}));
    quota.setTotal(Stock({{Resource::PERSON, 2}}));

    Stock expected({{Resource::PERSON, 2}});
    ASSERT_EQ(expected, quota.getTotal());
}

TEST(TestQuota, ChangeMetStock) {
    Quota quota;
    quota.setMet(Stock({{Resource::PERSON, 1}}));
    quota.setMet(Stock({{Resource::PERSON, 2}}));

    Stock expected({{Resource::PERSON, 2}});
    ASSERT_EQ(expected, quota.getMet());
}

TEST(TestQuota, ChangeUnmetStock) {
    Quota quota(Stock({{Resource::PERSON, 2}}));
    quota.setUnmet(Stock({{Resource::PERSON, 1}}));
    quota.setUnmet(Stock({{Resource::PERSON, 2}}));

    Stock expected({{Resource::PERSON, 2}});
    ASSERT_EQ(expected, quota.getUnmet());
}

TEST(TestQuota, MetCanBeHigherThanTotal) {
    Quota quota(
        Stock({{Resource::PERSON, 1}}),
        Stock({{Resource::PERSON, 2}})
    );

    ASSERT_EQ(Stock({{Resource::PERSON, 2}}), quota.getMet());
}
