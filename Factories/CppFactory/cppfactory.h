#ifndef CPPFACTORY_H
#define CPPFACTORY_H
#include<Interfaces.h>


class CppFactory:AbstractFactory
{
public:
    CppFactory();

    // AbstractFactory interface
public:
    std::shared_ptr<ClassUnit> GetClassUnit(std::string name, unsigned int flags) = 0;
    std::shared_ptr<MethodUnit> GetMethodUnit(std::string name, std::string returnType, unsigned int flags) = 0;
};

#endif // CPPFACTORY_H
