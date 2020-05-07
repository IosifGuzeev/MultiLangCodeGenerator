#ifndef JAVAPRINTCOMMAND_H
#define JAVAPRINTCOMMAND_H
#include <Interfaces.h>
#include <vector>

class JavaPrintCommand: public Unit
{
public:
    JavaPrintCommand();

    // Unit interface
public:
    void addSubUnit(const std::shared_ptr<Unit> &subUnit, Flags) override;
    std::vector<std::string> Compile(unsigned int level) override;
};

#endif // JAVAPRINTCOMMAND_H
