#include <tuple>

#include "gtest/gtest.h"

#include "NonZeroResourceMap.h"

class TestNonZeroResourceMapEqualityParam
    : public testing::TestWithParam<std::tuple<NonZeroResourceMap, NonZeroResourceMap, bool> >
{
    //
};

TEST_P(TestNonZeroResourceMapEqualityParam, ) {
    NonZeroResourceMap mapA;
    NonZeroResourceMap mapB;
    bool expectedIsEqual;
    std::tie(mapA, mapB, expectedIsEqual) = GetParam();

    ASSERT_EQ(expectedIsEqual, mapA == mapB);
    ASSERT_EQ(!expectedIsEqual, mapA != mapB);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    TestNonZeroResourceMapEqualityParam,
    testing::Values(
        std::make_tuple(
            NonZeroResourceMap()
            , NonZeroResourceMap()
            , true
        )
        , std::make_tuple(
            NonZeroResourceMap({{Resource::PERSON, 1}})
            , NonZeroResourceMap({{Resource::PERSON, 1}})
            , true
        )
        , std::make_tuple(
            NonZeroResourceMap({{Resource::PERSON, 2}})
            , NonZeroResourceMap({{Resource::PERSON, 2}})
            , true
        )
        , std::make_tuple(
            NonZeroResourceMap({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}})
            , NonZeroResourceMap({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}})
            , true
        )
        , std::make_tuple(
            NonZeroResourceMap({{Resource::PERSON, 1}})
            , NonZeroResourceMap()
            , false
        )
        , std::make_tuple(
            NonZeroResourceMap()
            , NonZeroResourceMap({{Resource::PERSON, 1}})
            , false
        )
        , std::make_tuple(
            NonZeroResourceMap({{Resource::PERSON, 1}})
            , NonZeroResourceMap({{Resource::PERSON, 2}})
            , false
        )
        , std::make_tuple(
            NonZeroResourceMap({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}})
            , NonZeroResourceMap({{Resource::PERSON, 1}})
            , false
        )
    )
);

TEST(TestNonZeroResourceMap, DefaultShouldHaveNoResources) {
    NonZeroResourceMap map;

    ASSERT_EQ(0, map.get(Resource::PERSON));
    ASSERT_EQ(0, map.get(Resource::COM_PRODUCT));
    ASSERT_EQ(0, map.get(Resource::IND_PRODUCT));
}

TEST(TestNonZeroResourceMap, OnePerson) {
    NonZeroResourceMap map({{Resource::PERSON, 1}});

    ASSERT_EQ(1, map.get(Resource::PERSON));
}

TEST(TestNonZeroResourceMap, OneComProduct) {
    NonZeroResourceMap map({{Resource::COM_PRODUCT, 1}});

    ASSERT_EQ(1, map.get(Resource::COM_PRODUCT));
}

TEST(TestNonZeroResourceMap, OneIndProduct) {
    NonZeroResourceMap map({{Resource::IND_PRODUCT, 1}});

    ASSERT_EQ(1, map.get(Resource::IND_PRODUCT));
}

TEST(TestNonZeroResourceMap, ManyOfOneResource) {
    NonZeroResourceMap map({{Resource::PERSON, 10}});

    ASSERT_EQ(10, map.get(Resource::PERSON));
}

TEST(TestNonZeroResourceMap, WhenAddingVariousShouldAddThemAll) {
    NonZeroResourceMap map;

    map.set(Resource::PERSON, 1);
    map.set(Resource::COM_PRODUCT, 2);
    map.set(Resource::IND_PRODUCT, 3);

    ASSERT_EQ(1, map.get(Resource::PERSON));
    ASSERT_EQ(2, map.get(Resource::COM_PRODUCT));
    ASSERT_EQ(3, map.get(Resource::IND_PRODUCT));
}

TEST(TestNonZeroResourceMap, WhenAddingAResourceShouldOnlyThatResource) {
    NonZeroResourceMap map;

    map.set(Resource::PERSON, 1);

    ASSERT_EQ(1, map.get(Resource::PERSON));
    ASSERT_EQ(0, map.get(Resource::COM_PRODUCT));
    ASSERT_EQ(0, map.get(Resource::IND_PRODUCT));
}

TEST(TestNonZeroResourceMap, WhenChangedCountShouldHaveNewestCount) {
    NonZeroResourceMap map({{Resource::PERSON, 1}});
    map.set(Resource::PERSON, 2);

    NonZeroResourceMap expected({{Resource::PERSON, 2}});

    ASSERT_EQ(expected, map);
}

TEST(TestNonZeroResourceMap, WhenEmptyShouldNotIterate) {
    NonZeroResourceMap map;

    int loops = 0;
    for(const auto& pair : map) {
        loops++;
    }

    ASSERT_EQ(0, loops);
}

TEST(TestNonZeroResourceMap, WhenEmptyShouldNotIterate2) {
    NonZeroResourceMap map({{Resource::PERSON, 0}});

    int loops = 0;
    for(const auto& pair : map) {
        loops++;
    }

    ASSERT_EQ(0, loops);
}

TEST(TestNonZeroResourceMap, WhenOneTypeShouldIterateOnce) {
    NonZeroResourceMap map({{Resource::PERSON, 1}});

    int loops = 0;
    for(const auto& pair : map) {
        loops++;
    }

    ASSERT_EQ(1, loops);
}

TEST(TestNonZeroResourceMap, WhenTwoTypesShouldIterateTwice) {
    NonZeroResourceMap map({{Resource::PERSON, 1}, {Resource::IND_PRODUCT, 1}});

    int loops = 0;
    for(const auto& pair : map) {
        loops++;
    }

    ASSERT_EQ(2, loops);
}

TEST(TestNonZeroResourceMap, WhenOneTypeAndChangedCountShouldIterateOnce) {
    NonZeroResourceMap map({{Resource::PERSON, 1}});
    map.set(Resource::PERSON, 2);

    int loops = 0;
    for(const auto& pair : map) {
        loops++;
    }

    ASSERT_EQ(1, loops);
}

TEST(TestNonZeroResourceMap, WhenOneResourceShouldIterateOverIt) {
    NonZeroResourceMap map({{Resource::PERSON, 1}});

    bool found = false;
    for(const auto& pair : map) {
        if(pair.first == Resource::PERSON && pair.second == 1) {
            found = true;
        }
    }

    ASSERT_TRUE(found);
}

TEST(TestNonZeroResourceMap, WhenTwoResourcesShouldIterateOverBoth) {
    NonZeroResourceMap map({{Resource::PERSON, 1}, {Resource::IND_PRODUCT, 1}});

    bool foundPerson = false;
    bool foundInd = false;
    for(const auto& pair : map) {
        if(pair.first == Resource::PERSON) {
            foundPerson = true;
        }
        else if(pair.first == Resource::IND_PRODUCT) {
            foundInd = true;
        }
    }

    ASSERT_TRUE(foundPerson && foundInd);
}
