#include "gtest/gtest.h"

#include "Stock.h"

namespace DivTest {
    struct TestData {
        Stock expected;
        Stock input;
        int div;
    };

    class DivTest : public testing::TestWithParam<TestData> {
        //
    };

    TEST_P(DivTest, ) {
        auto params = GetParam();

        ASSERT_EQ(params.expected, params.input / params.div);
    }

    INSTANTIATE_TEST_CASE_P(
        /* */,
        DivTest,
        testing::Values(
            TestData{Stock(), Stock(), 1},
            TestData{Stock(), Stock(), 2},
            TestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 1}}), 1},
            TestData{Stock(), Stock({{Resource::PERSON, 1}}), 2},
            TestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 2}}), 2},
            TestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 3}}), 2}
        )
    );
}
