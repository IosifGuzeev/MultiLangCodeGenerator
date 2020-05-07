#include "csharpmethodunit.h"

CSharpMethodUnit::CSharpMethodUnit(std::string name, std::string resultType, Flags flag)
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

void CSharpMethodUnit::addSubUnit(const std::shared_ptr<Unit> &subUnit, Unit::Flags accessType = 0)
{
    subUnits.push_back(subUnit);
}

std::vector<std::string> CSharpMethodUnit::Compile(unsigned int level)
{
    std::vector<std::string> result;
    result.push_back(modificator + resultType + " " + name + "()");
    result.push_back("{");
    for (auto &e: subUnits)
    {
        auto new_strings = e->Compile(level + 1);
        result.insert(result.end(), new_strings.begin(), new_strings.end());
    }
    result.push_back("}");
    for(auto& str: result)
        if(level > 0)
            str = "    " + str;
    return result;
}
