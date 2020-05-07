#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H
#include<Interfaces.h>
#include<Factories/CSharpFactory/csharpclassunit.h>
#include<Factories/CSharpFactory/csharpmethodunit.h>
#include<Factories/CSharpFactory/csharpprintcommand.h>


class CSharpFactory: public AbstractFactory
{
public:
    CSharpFactory(){};

    // AbstractFactory interface
public:
    std::shared_ptr<ClassUnit> GetClassUnit(std::string name, unsigned int flags) override;
    std::shared_ptr<MethodUnit> GetMethodUnit(std::string name, std::string returnType, unsigned int flags) override;
    std::shared_ptr<Unit> GetPrintComand() override;
};

#endif // CSHARPFACTORY_H
