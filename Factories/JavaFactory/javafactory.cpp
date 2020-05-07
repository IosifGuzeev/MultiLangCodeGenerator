#include "javafactory.h"

std::shared_ptr<ClassUnit> JavaFactory::GetClassUnit(std::string name, unsigned int flags)
{
    return std::shared_ptr<JavaClassUnit>(new JavaClassUnit(name));
}

std::shared_ptr<MethodUnit> JavaFactory::GetMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::shared_ptr<JavaMethodUnit>(new JavaMethodUnit(name, returnType));
}

std::shared_ptr<Unit> JavaFactory::GetPrintComand()
{
    return std::shared_ptr<JavaPrintCommand>(new JavaPrintCommand());
}
