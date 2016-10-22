#include "gtest/gtest.h"

#include "Stock.h"

struct DivEqualTestData {
    Stock expected;
    Stock input;
    int div;
};

class DivEqualTest : public testing::TestWithParam<DivEqualTestData> {
    //
};

TEST_P(DivEqualTest, NormaDiv) {
    auto params = GetParam();

    Stock result = params.input;
    result /= params.div;

    ASSERT_EQ(params.expected, result);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    DivEqualTest,
    testing::Values(
        DivEqualTestData{Stock(), Stock(), 1},
        DivEqualTestData{Stock(), Stock(), 2},
        DivEqualTestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 1}}), 1},
        DivEqualTestData{Stock(), Stock({{Resource::PERSON, 1}}), 2},
        DivEqualTestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 2}}), 2},
        DivEqualTestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 3}}), 2}
    )
);
