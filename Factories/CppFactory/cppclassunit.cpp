#include "Factories/CppFactory/cppclassunit.h"

CppClassUnit::CppClassUnit(std::string name)
{
    this->name = name;
    subUnits["public"] = UnitVector();
    subUnits["private"] = UnitVector();
    subUnits["protected"] = UnitVector();
}

void CppClassUnit::addSubUnit(const std::shared_ptr<Unit> &subUnit, Flags accessType)
{
    std::string key;
    switch (accessType) {
    case PUBLIC:
    {
        key = "public";
        break;
    }
    case PRIVATE:
    {
        key = "private";
        break;
    }
    case PROTECTED:
    {
        key = "protected";
        break;
    }
    default:
    {
        std::runtime_error("Wrong access type!");
        break;
    }
    }
    subUnits[key].push_back(subUnit);
}

std::vector<std::string> CppClassUnit::Compile(unsigned int level)
{
    std::vector<std::string> result;
    result.push_back("class " + name + "\n");
    result.push_back("{\n");
    for (auto &unitsVec: subUnits)
    {
        if(unitsVec.second.size() > 0)
        {
            result.push_back(unitsVec.first + ":\n");
            for(auto &e: unitsVec.second)
            {
                auto new_strings = e->Compile(level + 1);
                result.insert(result.end(), new_strings.begin(), new_strings.end());
            }
        }
    }
    result.push_back("};\n");
    for(auto& str: result)
        if(level > 0)
            str = "    " + str;
    return result;
}
