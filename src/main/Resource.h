#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <iostream>
#include <map>
#include <string>

enum class Resource {
    COM_PRODUCT,
    ELECTRICITY,
    IND_PRODUCT,
    PERSON
};

static std::map<Resource, std::string> resourceToString = {
    {Resource::COM_PRODUCT, "COM_PRODUCT"},
    {Resource::ELECTRICITY, "ELECTRICITY"},
    {Resource::IND_PRODUCT, "IND_PRODUCT"},
    {Resource::PERSON, "PERSON"}
};

inline std::ostream& operator<<(std::ostream& stream, const Resource& resource) {
    stream << resourceToString[resource];

    return stream;
}

#endif
