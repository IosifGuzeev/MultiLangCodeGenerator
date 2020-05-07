#include "csharpprintcommand.h"

CSharpPrintCommand::CSharpPrintCommand()
{

}

void CSharpPrintCommand::addSubUnit(const std::shared_ptr<Unit> &subUnit, Unit::Flags)
{
    throw std::runtime_error("Cant add subunits to print command!");
}

std::vector<std::string> CSharpPrintCommand::Compile(unsigned int level)
{
    std::string comand = "Console.WriteLine(\"Hello world!\");";
    if(level > 0)
    {
        comand = "    " + comand;
    }
    std::vector<std::string> result({comand});
    return result;
}
