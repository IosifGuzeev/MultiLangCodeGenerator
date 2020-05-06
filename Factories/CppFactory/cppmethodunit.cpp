#include "Factories/CppFactory/cppmethodunit.h"

CppMethodUnit::CppMethodUnit(std::string name, std::string resultType, Flags flag)
{
    this->name = name;
    this->resultType = resultType;
    switch (flag) {
    case 0:
    {
        modificator = "";
        break;
    }
    case 1:
    {
        modificator = "static ";
        break;
    }
    case 2:
    {
        modificator = "const ";
        break;
    }
    case 3:
    {
        modificator = "virtual ";
        break;
    }
    default:
    {
        throw std::runtime_error("flag not found!");
    }
    }
}

void CppMethodUnit::addSubUnit(const std::shared_ptr<Unit> &subUnit, Unit::Flags accessType = 0)
{
    subUnits.push_back(subUnit);
}

std::vector<std::string> CppMethodUnit::Compile(unsigned int level)
{
    std::vector<std::string> result;
    result.push_back(modificator + resultType + " " + name + "()\n");
    result.push_back("{\n");
    for (auto &e: subUnits)
    {
        auto new_strings = e->Compile(level + 1);
        result.insert(result.end(), new_strings.begin(), new_strings.end());
    }
    result.push_back("}\n");
    for(auto& str: result)
        if(level > 0)
            str = "    " + str;
    return result;
}
