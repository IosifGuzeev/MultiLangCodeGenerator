#ifndef CPPPRINTCOMMAND_H
#define CPPPRINTCOMMAND_H
#include <Interfaces.h>
#include <vector>

class CppPrintCommand: public Unit
{
public:
    CppPrintCommand();

    // Unit interface
public:
    void addSubUnit(const std::shared_ptr<Unit> &subUnit, Flags) override;
    std::vector<std::string> Compile(unsigned int level) override;
};

#endif // CPPPRINTCOMMAND_H
