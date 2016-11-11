#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>  // ostream
#include <set>
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

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::set<T>& set) {
    stream << "{";

    for(auto it = set.begin(); it != set.end(); it++) {
        if(it == set.begin()) {
            stream << *it;
        }
        else{
            stream << ", " << *it;
        }
    }

    stream << "}" << std::endl;

    return stream;
}

#endif
