#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "docopt.h"

TEST(TestDocopt, ShouldNotThrow) {
    const char doc[] = "Usage: test";
    std::vector<std::string> input;

    docopt::docopt_parse(doc, input, false);
}

TEST(TestDocopt, ShouldNotThrow2) {
    const char doc[] = "Usage: test [a]";
    std::vector<std::string> input;

    docopt::docopt_parse(doc, input, false);
}

TEST(TestDocopt, ShouldNotThrow3) {
    const char doc[] = "Usage: test [a]";
    std::vector<std::string> input = {"a"};

    docopt::docopt_parse(doc, input, false);
}

TEST(TestDocopt, ShouldNotThrow4) {
    const char doc[] =
        "Usage:\n"
        "    test one\n"
        "    test two";
    std::vector<std::string> input = {"one"};

    docopt::docopt_parse(doc, input, false);
}

TEST(TestDocopt, ShouldNotThrow5) {
    const char doc[] =
        "Usage:\n"
        "    test one\n"
        "    test two";
    std::vector<std::string> input = {"two"};

    docopt::docopt_parse(doc, input, false);
}
