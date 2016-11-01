#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>  // istream_iterator
#include <sstream>  // istringstream
#include <string>
#include <vector>

namespace VectorUtils {
    template <typename T>
    std::vector<T> getTail(std::vector<T> vec) {
        std::vector<T> tail;

        if(vec.size() > 1) {;
            return {vec.begin() + 1, vec.end()};
        }

        return tail;
    }
}

namespace StringUtils {
    std::vector<std::string> words(std::string);
}

#endif