#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H
#include <Interfaces.h>
#include <map>
#include <exception>


class CSharpMethodUnit : public MethodUnit
{
    using UnitVector = std::vector<std::shared_ptr<Unit>>;

    std::string name;
    std::string resultType;
    std::string modificator;
    UnitVector subUnits;

public:

    CSharpMethodUnit(std::string name, std::string resultType, Flags flags = 0);
    void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags accessType) override;
    std::vector<std::string> Compile(unsigned int level) override;
};
#endif // CSHARPMETHODUNIT_H
