#include "csharpfactory.h"


std::shared_ptr<ClassUnit> CSharpFactory::GetClassUnit(std::string name, unsigned int flags)
{
    return std::shared_ptr<CSharpClassUnit>(new CSharpClassUnit(name));
}

std::shared_ptr<MethodUnit> CSharpFactory::GetMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::shared_ptr<CSharpMethodUnit>(new CSharpMethodUnit(name, returnType));
}

std::shared_ptr<Unit> CSharpFactory::GetPrintComand()
{
    return std::shared_ptr<CSharpPrintCommand>(new CSharpPrintCommand());
}
