#include "gtest/gtest.h"

#include "Stock.h"


namespace EqualTest {
    struct TestData {
        Stock stockA;
        Stock stockB;
    };

    class NotEqualTest : public testing::TestWithParam<TestData> {
        //
    };

    TEST_P(NotEqualTest, ) {
        auto params = GetParam();

        ASSERT_NE(params.stockA, params.stockB);
    }

    INSTANTIATE_TEST_CASE_P(
        /* */,
        NotEqualTest,
        testing::Values(
            TestData{Stock({{Resource::PERSON, 1}}), Stock()},
            TestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::ELECTRICITY, 1}})},
            TestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 2}})}
        )
    );
};
