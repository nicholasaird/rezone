#include "gtest/gtest.h"

#include "Quota.hpp"
#include "Resource.hpp"
#include "Stock.hpp"

TEST(TestQuota, EmptyQuota) {
    Quota quota;

    Stock emptyStock;
    ASSERT_EQ(emptyStock, quota.getTotal());
    ASSERT_EQ(emptyStock, quota.getMet());
    ASSERT_EQ(emptyStock, quota.getUnmet());
}

TEST(TestQuota, CompletelyUnmetQuota) {
    Stock totalStock({{Resource::PERSON, 1}});
    Quota quota(totalStock);

    Stock emptyStock;
    ASSERT_EQ(totalStock, quota.getTotal());
    ASSERT_EQ(emptyStock, quota.getMet());
    ASSERT_EQ(totalStock, quota.getUnmet());
}

TEST(TestQuota, PartiallyUnmetQuota) {
    Stock totalStock({{Resource::PERSON, 2}});
    Stock metStock({{Resource::PERSON, 1}});
    Stock unmetStock({{Resource::PERSON, 1}});
    Quota quota(totalStock, metStock);

    ASSERT_EQ(totalStock, quota.getTotal());
    ASSERT_EQ(metStock, quota.getMet());
    ASSERT_EQ(unmetStock, quota.getUnmet());
}

TEST(TestQuota, PartiallyUnmetQuotaUsingSetter) {
    Stock totalStock({{Resource::PERSON, 2}});
    Stock metStock({{Resource::PERSON, 1}});
    Stock unmetStock({{Resource::PERSON, 1}});

    Quota quota(totalStock);
    quota.setMet(metStock);

    ASSERT_EQ(totalStock, quota.getTotal());
    ASSERT_EQ(metStock, quota.getMet());
    ASSERT_EQ(unmetStock, quota.getUnmet());
}

TEST(TestQuota, CompletelyMetQuotaUsing) {
    Stock totalStock({{Resource::PERSON, 2}});
    Stock emptyStock;

    Quota quota(totalStock, totalStock);

    ASSERT_EQ(totalStock, quota.getTotal());
    ASSERT_EQ(totalStock, quota.getMet());
    ASSERT_EQ(emptyStock, quota.getUnmet());
}

TEST(TestQuota, ChangeTotalStock) {
    Stock oldStock({{Resource::PERSON, 1}});
    Stock newStock({{Resource::PERSON, 2}});
    Quota quota;
    quota.setTotal(oldStock);
    quota.setTotal(newStock);

    ASSERT_EQ(newStock, quota.getTotal());
}

TEST(TestQuota, ChangeMetStock) {
    Stock oldStock({{Resource::PERSON, 1}});
    Stock newStock({{Resource::PERSON, 2}});
    Quota quota;
    quota.setMet(oldStock);
    quota.setMet(newStock);

    ASSERT_EQ(newStock, quota.getMet());
}

TEST(TestQuota, ChangeUnmetStock) {
    Stock totalStock({{Resource::PERSON, 2}});
    Stock oldStock({{Resource::PERSON, 1}});
    Stock newStock({{Resource::PERSON, 2}});
    Quota quota(totalStock);
    quota.setUnmet(oldStock);
    quota.setUnmet(newStock);

    ASSERT_EQ(newStock, quota.getUnmet());
}
