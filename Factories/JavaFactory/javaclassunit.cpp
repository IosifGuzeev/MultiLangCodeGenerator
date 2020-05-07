#include "javaclassunit.h"


JavaClassUnit::JavaClassUnit(std::string name)
{
    this->name = name;
    subUnits["public"] = UnitVector();
    subUnits["private"] = UnitVector();
    subUnits["protected"] = UnitVector();
}

void JavaClassUnit::addSubUnit(const std::shared_ptr<Unit> &subUnit, Flags accessType)
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

std::vector<std::string> JavaClassUnit::Compile(unsigned int level)
{
    std::vector<std::string> result;
    result.push_back("class " + name);
    result.push_back("{");
    for (auto &unitsVec: subUnits)
    {
        if(unitsVec.second.size() > 0)
        {
            //result.push_back(unitsVec.first + ":");
            for(auto &e: unitsVec.second)
            {
                auto new_strings = e->Compile(level + 1);
                int first_letter = 0;
                for(;new_strings[0][first_letter] == ' '; first_letter++);
                new_strings[0].insert(first_letter, unitsVec.first + " ");
                result.insert(result.end(), new_strings.begin(), new_strings.end());
            }
        }
    }
    result.push_back("};");
    for(auto& str: result)
        if(level > 0)
            str = "    " + str;
    return result;
}
