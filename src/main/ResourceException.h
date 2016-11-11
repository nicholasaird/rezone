#ifndef RESOURCEEXCEPTION_HPP
#define RESOURCEEXCEPTION_HPP

#include <stdexcept>
#include <string>

class ResourceException : public std::runtime_error {
public:
    ResourceException(const std::string& message);
};

#endif
