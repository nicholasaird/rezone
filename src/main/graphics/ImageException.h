#include <stdexcept>
#include <string>

class ImageException : public std::runtime_error {
public:
    ImageException(const std::string& message);
};
