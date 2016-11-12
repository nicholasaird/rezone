#ifndef DIMEXCEPTION_HPP
#define DIMEXCEPTION_HPP

#include <stdexcept>
#include <string>

class DimException : public std::runtime_error {
public:
    DimException(int x, int y, std::string message);
};

#endif
