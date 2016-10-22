#include "gtest/gtest.h"

#include "Stock.h"

namespace EqualTest {
    struct TestData {
        Stock stockA;
        Stock stockB;
    };

    class EqualTest : public testing::TestWithParam<TestData> {
        //
    };

    TEST_P(EqualTest, ) {
        auto params = GetParam();

        ASSERT_EQ(params.stockA, params.stockB);
    }

    INSTANTIATE_TEST_CASE_P(
        /* */,
        EqualTest,
        testing::Values(
            TestData{Stock(), Stock()},
            TestData{Stock({{Resource::PERSON, 0}}), Stock()},
            TestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 1}})}
        )
    );
};
