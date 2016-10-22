#include "gtest/gtest.h"

#include "Stock.h"

namespace DivEqualTest {
    struct TestData {
        Stock input;
        int div;
        Stock expected;
    };

    class DivEqualTest : public testing::TestWithParam<TestData> {
        //
    };

    TEST_P(DivEqualTest, ) {
        auto params = GetParam();

        Stock result = params.input;
        result /= params.div;

        ASSERT_EQ(params.expected, result);
    }

    INSTANTIATE_TEST_CASE_P(
        /* */,
        DivEqualTest,
        testing::Values(
            TestData{Stock(), 1, Stock()},
            TestData{Stock(), 2, Stock()},
            TestData{Stock({{Resource::PERSON, 1}}), 1, Stock({{Resource::PERSON, 1}})},
            TestData{Stock({{Resource::PERSON, 1}}), 2, Stock()},
            TestData{Stock({{Resource::PERSON, 2}}), 2, Stock({{Resource::PERSON, 1}})},
            TestData{Stock({{Resource::PERSON, 3}}), 2, Stock({{Resource::PERSON, 1}})}
        )
    );
};
