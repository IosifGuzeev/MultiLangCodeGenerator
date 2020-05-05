#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H
#include <Interfaces.h>
#include <map>

class CppClassUnit : public ClassUnit
{
    using UnitVector = std::vector<std::shared_ptr<Unit>>;

    std::string name;
    std::map<std::string, UnitVector> subUnits;

public:

    enum AccessType{
        PUBLIC = 0,
        PRIVATE = 1,
        PROTECTED = 2,
    };

    CppClassUnit(std::string name);
    void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags accessType) override;
    std::vector<std::string> Compile(unsigned int level = 0) override;
};

#endif // CPPCLASSUNIT_H
