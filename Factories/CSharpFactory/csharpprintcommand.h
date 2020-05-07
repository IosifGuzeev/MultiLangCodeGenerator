#ifndef CSHARPPRINTCOMMAND_H
#define CSHARPPRINTCOMMAND_H
#include <Interfaces.h>
#include <vector>

class CSharpPrintCommand: public Unit
{
public:
    CSharpPrintCommand();

    // Unit interface
public:
    void addSubUnit(const std::shared_ptr<Unit> &subUnit, Flags) override;
    std::vector<std::string> Compile(unsigned int level) override;
};
#endif // CSHARPPRINTCOMMAND_H
