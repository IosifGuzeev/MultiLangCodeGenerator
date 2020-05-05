#ifndef CODEFACTORY_H
#define CODEFACTORY_H
#include <Interfaces.h>
#include <Utilities/writers.h>
#include <Factories/CppFactory/cppfactory.h>

class CodeFactory
{
    using ClassPtr = std::shared_ptr<ClassUnit>;
    AbstractFactory *factory;
    Writer *writer;
    std::map<std::string, ClassPtr> classes;

public:
    enum Languages{
        cpp = 0,
        c_sharp = 1,
        java = 2
    };

    CodeFactory(Languages langauge, Writer *_writer = nullptr);
    ~CodeFactory();
    void AddClassUnit(std::string name, unsigned int flags = 0);
    void AddMethodUnit(std::string className, Unit::Flags accessType, std::string name, std::string returnType, Unit::Flags flags);
    void Compile();
};

#endif // CODEFACTORY_H
