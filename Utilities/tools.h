#ifndef TOOLS_H
#define TOOLS_H
#include <string>
#include <interfaces.h>

std::string AccessCodeToString(Unit::Flags accessType)
{
    std::string key;
    switch (accessType) {
    case 0:
    {
        key = "public";
        break;
    }
    case 1:
    {
        key = "private";
        break;
    }
    case 2:
    {
        key = "protected";
        break;
    }
    default:
    {
        std::runtime_error("Wrong access type!");
        key = "";
        break;
    }
    }
    return key;
}

std::vector<std::string> CreateTabing(std::vector<std::string> Units, int level)
{
    std::vector<std::string> result;
    for(auto& str: Units)
        result.push_back(std::string(level * 4, ' ') + str);
    return result;
}

#endif // TOOLS_H
