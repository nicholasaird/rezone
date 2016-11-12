#ifndef UNFOUNDARGUMENTEXCEPTION_HPP
#define UNFOUNDARGUMENTEXCEPTION_HPP

#include <stdexcept>

class UnfoundArgumentException : public std::runtime_error {
public:
    UnfoundArgumentException(const std::string& argumentName);
};

#endif
