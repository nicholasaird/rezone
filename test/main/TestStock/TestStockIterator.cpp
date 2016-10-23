#include "gtest/gtest.h"

#include "Stock.h"

TEST(TestStockIterator, NumberOfLoopsWhenEmpty) {
    Stock stock;

    int numLoops = 0;
    for(const auto& pair : stock) {
        numLoops++;
    }

    ASSERT_EQ(0, numLoops);
}

TEST(TestStockIterator, NumberOfLoops) {
    Stock stock({{Resource::PERSON, 1}});

    int numLoops = 0;
    for(const auto& pair : stock) {
        numLoops++;
    }

    ASSERT_EQ(1, numLoops);
}

TEST(TestStockIterator, NumberOfLoops2) {
    Stock stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 1}});

    int numLoops = 0;
    for(const auto& pair : stock) {
        numLoops++;
    }

    ASSERT_EQ(2, numLoops);
}

TEST(TestStockIterator, CorrectResourcesAndCounts) {
    Stock stock({{Resource::PERSON, 1}});

    bool iteratedOverPerson = false;
    for(const auto& pair : stock) {
        if(pair.first == Resource::PERSON && pair.second == 1) {
            iteratedOverPerson = true;
        }
        else {
            FAIL() << "Iterated over wrong resource or count (" << pair.first << ", " << pair.second << ")";
        }
    }

    ASSERT_TRUE(iteratedOverPerson);
}

TEST(TestStockIterator, CorrectResourcesAndCounts2) {
    Stock stock({{Resource::PERSON, 1}, {Resource::ELECTRICITY, 2}});

    bool iteratedOverPerson = false;
    bool iteratedOverElectricity = false;
    for(const auto& pair : stock) {
        if(pair.first == Resource::PERSON && pair.second == 1) {
            iteratedOverPerson = true;
        }
        else if(pair.first == Resource::ELECTRICITY && pair.second == 2) {
            iteratedOverElectricity = true;
        }
        else {
            FAIL() << "Iterated over wrong resource or count (" << pair.first << ", " << pair.second << ")";
        }
    }

    ASSERT_TRUE(iteratedOverPerson);
    ASSERT_TRUE(iteratedOverElectricity);
}
