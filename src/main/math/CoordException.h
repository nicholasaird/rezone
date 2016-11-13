#ifndef COORDEXCEPTION_HPP
#define COORDEXCEPTION_HPP

#include <stdexcept>
#include <string>

class CoordException : public std::runtime_error {
public:
    CoordException(int x, int y, std::string message);
};

#endif
