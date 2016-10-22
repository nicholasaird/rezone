#include "gtest/gtest.h"

#include "Stock.h"

struct DivTestData {
    Stock expected;
    Stock input;
    int div;
};

class DivTest : public testing::TestWithParam<DivTestData> {
    //
};

TEST_P(DivTest, NormaDiv) {
    auto params = GetParam();

    ASSERT_EQ(params.expected, params.input / params.div);
}

INSTANTIATE_TEST_CASE_P(
    /* */,
    DivTest,
    testing::Values(
        DivTestData{Stock(), Stock(), 1},
        DivTestData{Stock(), Stock(), 2},
        DivTestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 1}}), 1},
        DivTestData{Stock(), Stock({{Resource::PERSON, 1}}), 2},
        DivTestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 2}}), 2},
        DivTestData{Stock({{Resource::PERSON, 1}}), Stock({{Resource::PERSON, 3}}), 2}
    )
);
