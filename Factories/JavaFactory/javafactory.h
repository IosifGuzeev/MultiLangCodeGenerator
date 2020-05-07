#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H
#include<Interfaces.h>
#include<Factories/JavaFactory/javaclassunit.h>
#include<Factories/JavaFactory/javamethodunit.h>
#include<Factories/JavaFactory/javaprintcommand.h>


class JavaFactory: public AbstractFactory
{
public:
    JavaFactory(){};

    // AbstractFactory interface
public:
    std::shared_ptr<ClassUnit> GetClassUnit(std::string name, unsigned int flags) override;
    std::shared_ptr<MethodUnit> GetMethodUnit(std::string name, std::string returnType, unsigned int flags) override;
    std::shared_ptr<Unit> GetPrintComand() override;
};

#endif // JAVAFACTORY_H
