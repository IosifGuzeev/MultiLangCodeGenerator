#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H
#include <Interfaces.h>
#include <map>
#include <exception>


class JavaMethodUnit : public MethodUnit
{
    using UnitVector = std::vector<std::shared_ptr<Unit>>;

    std::string name;
    std::string resultType;
    std::string modificator;
    UnitVector subUnits;

public:

    JavaMethodUnit(std::string name, std::string resultType, Flags flags = 0);
    void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags accessType) override;
    std::vector<std::string> Compile(unsigned int level) override;
};

#endif // JAVAMETHODUNIT_H
