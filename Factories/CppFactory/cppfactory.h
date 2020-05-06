#ifndef CPPFACTORY_H
#define CPPFACTORY_H
#include<Interfaces.h>
#include<Factories/CppFactory/cppclassunit.h>
#include<Factories/CppFactory/cppmethodunit.h>
#include<Factories/CppFactory/cppprintcommand.h>

class CppFactory: public AbstractFactory
{
public:
    CppFactory(){};

    // AbstractFactory interface
public:
    std::shared_ptr<ClassUnit> GetClassUnit(std::string name, unsigned int flags) override;
    std::shared_ptr<MethodUnit> GetMethodUnit(std::string name, std::string returnType, unsigned int flags) override;
    std::shared_ptr<Unit> GetPrintComand();
};

#endif // CPPFACTORY_H
