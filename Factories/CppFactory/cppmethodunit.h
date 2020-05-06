#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H
#include <Interfaces.h>
#include <map>
#include <exception>
class CppMethodUnit : public MethodUnit
{
    using UnitVector = std::vector<std::shared_ptr<Unit>>;

    std::string name;
    std::string resultType;
    std::string modificator;
    UnitVector subUnits;

public:

    CppMethodUnit(std::string name, std::string resultType, Flags flags = 0);
    void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags accessType) override;
    std::vector<std::string> Compile(unsigned int level) override;
};
#endif // CPPMETHODUNIT_H
