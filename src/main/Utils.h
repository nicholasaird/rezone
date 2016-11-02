#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>  // istream_iterator
#include <iostream>
#include <set>
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

namespace SetUtils {
    template<typename T>
    void print(const std::set<T>& set) {
        std::cout << "{";
        for(const auto& element : set) {
            std::cout << element << ", ";
        }
        std::cout << "}" << std::endl;
    }
}

#endif
