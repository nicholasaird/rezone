#include "gtest/gtest.h"

#include "Command/CommandArguments.h"
#include "Command/UnfoundArgumentException.h"
#include "Command/WrongTypeArgumentException.h"

TEST(TestCommandArguments, RetrieveAsIntWhenIntShouldNotThrow) {
    CommandArguments args;
    args.add("a", 0);

    ASSERT_EQ(0, args.getInt("a"));
}

TEST(TestCommandArguments, RetrieveAsIntWhenIntShouldNotThrow2) {
    CommandArguments args;
    args.add("a", "0");

    ASSERT_EQ(0, args.getInt("a"));
}

TEST(TestCommandArguments, RetrieveAsStringWhenIntShouldNotThrow) {
    CommandArguments args;
    args.add("a", 0);

    ASSERT_EQ("0", args.getString("a"));
}

TEST(TestCommandArguments, RetrieveAsStringWhenStringShouldNotThrow) {
    CommandArguments args;
    args.add("a", "0");

    ASSERT_EQ("0", args.getString("a"));
}

TEST(TestCommandArguments, RetrieveAsIntWhenStringShouldThrow) {
    CommandArguments args;
    args.add("a", "val");

    ASSERT_THROW(args.getInt("a"), WrongTypeArgumentException);
}

TEST(TestCommandArguments, RetrieveNonexistantArgumentShouldThrow) {
    CommandArguments args;

    ASSERT_THROW(args.getInt("nonExistent"), UnfoundArgumentException);
}

TEST(TestCommandArguments, RetrieveNonexistantArgumentShouldThrow2) {
    CommandArguments args;

    ASSERT_THROW(args.getString("nonExistent"), UnfoundArgumentException);
}
