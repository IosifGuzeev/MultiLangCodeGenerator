#include "cppfactory.h"

std::shared_ptr<ClassUnit> CppFactory::GetClassUnit(std::string name, unsigned int flags)
{
    return std::shared_ptr<CppClassUnit>(new CppClassUnit(name));
}

std::shared_ptr<MethodUnit> CppFactory::GetMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::shared_ptr<CppMethodUnit>(new CppMethodUnit(name, returnType));
}
