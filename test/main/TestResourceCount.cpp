#include "gtest/gtest.h"

#include "ResourceCount.hpp"

TEST(TestResourceCount, EmptyCountShouldHaveAll0) {
    ResourceCount count;

    ASSERT_EQ(0, count.get(Resource::PERSON));
    ASSERT_EQ(0, count.get(Resource::COM_PRODUCT));
    ASSERT_EQ(0, count.get(Resource::IND_PRODUCT));
}

TEST(TestResourceCount, AddOnePerson) {
    ResourceCount count;

    count.set(Resource::PERSON, 1);

    ASSERT_EQ(1, count.get(Resource::PERSON));
}

TEST(TestResourceCount, AddOneComProduct) {
    ResourceCount count;

    count.set(Resource::COM_PRODUCT, 1);

    ASSERT_EQ(1, count.get(Resource::COM_PRODUCT));
}

TEST(TestResourceCount, AddOneIndProduct) {
    ResourceCount count;

    count.set(Resource::IND_PRODUCT, 1);

    ASSERT_EQ(1, count.get(Resource::IND_PRODUCT));
}

TEST(TestResourceCount, AddManyPerson) {
    ResourceCount count;

    count.set(Resource::PERSON, 10);

    ASSERT_EQ(10, count.get(Resource::PERSON));
}

TEST(TestResourceCount, AddVariousResources) {
    ResourceCount count;

    count.set(Resource::PERSON, 1);
    count.set(Resource::COM_PRODUCT, 2);
    count.set(Resource::IND_PRODUCT, 3);

    ASSERT_EQ(1, count.get(Resource::PERSON));
    ASSERT_EQ(2, count.get(Resource::COM_PRODUCT));
    ASSERT_EQ(3, count.get(Resource::IND_PRODUCT));
}

TEST(TestResourceCount, AddingResourceShouldAddOnlyThatResource) {
    ResourceCount count;

    count.set(Resource::PERSON, 1);

    ASSERT_EQ(1, count.get(Resource::PERSON));
    ASSERT_EQ(0, count.get(Resource::COM_PRODUCT));
    ASSERT_EQ(0, count.get(Resource::IND_PRODUCT));
}

TEST(TestResourceCount, CountShouldHaveNewestValue) {
    ResourceCount count;

    count.set(Resource::PERSON, 1);
    count.set(Resource::PERSON, 2);

    ASSERT_EQ(2, count.get(Resource::PERSON));
}

TEST(TestResourceCount, WhenEmptyShouldNotIterate) {
    ResourceCount count;

    int loops = 0;
    for(auto pair : count) {
        loops++;
    }

    ASSERT_EQ(0, loops);
}

TEST(TestResourceCount, WhenEmptyShouldNotIterate2) {
    ResourceCount count({{Resource::PERSON, 0}});

    int loops = 0;
    for(auto pair : count) {
        loops++;
    }

    ASSERT_EQ(0, loops);
}

TEST(TestResourceCount, WhenOneTypeShouldIterateOnce) {
    ResourceCount count;
    count.set(Resource::PERSON, 1);

    int loops = 0;
    for(auto pair : count) {
        loops++;
    }

    ASSERT_EQ(1, loops);
}

TEST(TestResourceCount, WhenTwoTypesShouldIterateTwice) {
    ResourceCount count;
    count.set(Resource::PERSON, 1);
    count.set(Resource::IND_PRODUCT, 1);

    int loops = 0;
    for(auto pair : count) {
        loops++;
    }

    ASSERT_EQ(2, loops);
}

TEST(TestResourceCount, WhenOneTypeAndChangedCountShouldIterateOnce) {
    ResourceCount count;
    count.set(Resource::PERSON, 1);
    count.set(Resource::PERSON, 2);

    int loops = 0;
    for(auto pair : count) {
        loops++;
    }

    ASSERT_EQ(1, loops);
}

TEST(TestResourceCount, IterationShouldFindSingleResource) {
    ResourceCount count;
    count.set(Resource::PERSON, 1);

    bool found = false;
    for(auto pair : count) {
        if(pair.first == Resource::PERSON) {
            found = true;
        }
    }

    ASSERT_TRUE(found);
}

TEST(TestResourceCount, IterationShouldFindTwoResources) {
    ResourceCount count;
    count.set(Resource::PERSON, 1);
    count.set(Resource::IND_PRODUCT, 1);

    bool foundPerson = false;
    bool foundInd = false;
    for(auto pair : count) {
        if(pair.first == Resource::PERSON) {
            foundPerson = true;
        }
        else if(pair.first == Resource::IND_PRODUCT) {
            foundInd = true;
        }
    }

    ASSERT_TRUE(foundPerson && foundInd);
}

TEST(TestResourceCount, IterationShouldProvideCorrectCount) {
    ResourceCount count;
    count.set(Resource::PERSON, 1);

    bool correctCount = false;
    for(auto pair : count) {
        if(pair.first == Resource::PERSON && pair.second == 1) {
            correctCount = true;
        }
    }

    ASSERT_TRUE(correctCount);
}

TEST(TestResourceCount, EqualEmptyResourceCounts) {
    ResourceCount countA;
    ResourceCount countB;

    ASSERT_EQ(countA, countB);
}

TEST(TestResourceCount, EqualEmptyResourceCounts2) {
    ResourceCount countA({{Resource::PERSON, 0}});
    ResourceCount countB;

    ASSERT_EQ(countA, countB);
}

TEST(TestResourceCount, EqualSimpleResourceCounts) {
    ResourceCount countA({{Resource::PERSON, 1}});
    ResourceCount countB({{Resource::PERSON, 1}});

    ASSERT_EQ(countA, countB);
}

TEST(TestResourceCount, WhenEmptyAndNonEmptyShouldBeNonEqual) {
    ResourceCount countA({{Resource::PERSON, 1}});
    ResourceCount countB;

    ASSERT_NE(countA, countB);
}

TEST(TestResourceCount, WhenDifferentTypesShouldBeNonEqual) {
    ResourceCount countA({{Resource::PERSON, 1}});
    ResourceCount countB({{Resource::IND_PRODUCT, 1}});

    ASSERT_NE(countA, countB);
}

TEST(TestResourceCount, WhenDifferentCountsShouldBeNonEqual) {
    ResourceCount countA({{Resource::PERSON, 1}});
    ResourceCount countB({{Resource::PERSON, 2}});

    ASSERT_NE(countA, countB);
}
