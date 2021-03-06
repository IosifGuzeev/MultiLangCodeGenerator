#include "cppprintcommand.h"

CppPrintCommand::CppPrintCommand()
{

}

void CppPrintCommand::addSubUnit(const std::shared_ptr<Unit> &subUnit, Unit::Flags)
{
    throw std::runtime_error("Cant add subunits to print command!");
}

std::vector<std::string> CppPrintCommand::Compile(unsigned int level)
{
    std::string comand = "std::cout << \"Hello world!\" << std::endl;";
    if(level > 0)
    {
        comand = "    " + comand;
    }
    std::vector<std::string> result({comand});
    return result;
}
