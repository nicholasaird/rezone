#include "Utils.h"

std::vector<std::string> StringUtils::words(std::string line) {
    std::istringstream iss(line);
    std::istream_iterator<std::string> beg(iss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> tokens(beg, end);

    return tokens;
}
