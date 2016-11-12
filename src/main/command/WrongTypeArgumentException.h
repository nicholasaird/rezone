#ifndef WRONGTYPEARGUMENTEXCEPTION_HPP
#define WRONGTYPEARGUMENTEXCEPTION_HPP

#include <stdexcept>

class WrongTypeArgumentException : public std::runtime_error {
public:
    WrongTypeArgumentException(const std::string& message);
};

#endif
