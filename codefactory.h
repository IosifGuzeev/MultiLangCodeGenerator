#ifndef CODEFACTORY_H
#define CODEFACTORY_H
#include <Interfaces.h>
#include <Utilities/writers.h>
#include <Factories/CppFactory/cppfactory.h>
#include <Factories/JavaFactory/javafactory.h>
#include <Factories/CSharpFactory/csharpfactory.h>

class CodeFactory
{
    using ClassPtr = std::shared_ptr<ClassUnit>;
    using MethodPtr = std::shared_ptr<MethodUnit>;

    struct MethodInfo
    {
        std::string name;
        MethodPtr ptr;
    };

    AbstractFactory *factory;
    Writer *writer;
    bool IsOwnWriter;

    std::map<std::string, ClassPtr> classes;
    std::map<ClassPtr, std::vector<MethodInfo>> classMethods;

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
    void AddPrintComand(std::string className, std::string methodName);
    void Compile();
};

#endif // CODEFACTORY_H
