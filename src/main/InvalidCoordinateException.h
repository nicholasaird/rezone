#ifndef INVALIDCOORDINATEEXCEPTION_HPP
#define INVALIDCOORDINATEEXCEPTION_HPP

#include <stdexcept>

class InvalidCoordinateException : public std::runtime_error {
public:
    InvalidCoordinateException(int x, int y, int maxWidth, int maxHeight);
};

#endif
