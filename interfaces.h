#ifndef INTERFACES_H
#define INTERFACES_H
#include <memory>
#include <string>
#include <vector>

class Unit
{
public:

    using Flags = unsigned int;

    virtual ~Unit() = default;

    virtual void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags) = 0;
    virtual std::vector<std::string> Compile(unsigned int level = 0) = 0;
};

class ClassUnit : public Unit {};

class MethodUnit : public Unit {};

class AbstractFactory
{
public:
    virtual std::shared_ptr<ClassUnit> GetClassUnit(std::string name, unsigned int flags = 0) = 0;
    virtual std::shared_ptr<MethodUnit> GetMethodUnit(std::string name, std::string returnType, unsigned int flags) = 0;
};

typedef std::vector<std::shared_ptr<Unit>> UnitVector;

#endif // INTERFACES_H
