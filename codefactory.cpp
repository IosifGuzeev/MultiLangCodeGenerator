#include "codefactory.h"

CodeFactory::CodeFactory(Languages langauge, Writer *_writer)
{
    switch (langauge) {
    case CodeFactory::cpp:
    {
        factory = new CppFactory();
        break;
    }
    default:
    {
        throw std::runtime_error("Wrong language id!");
        break;
    }
    };

    if(_writer == nullptr)
    {
        writer = new ConsoleWriter();
    }
    else
    {
        writer = _writer;
    }
}

CodeFactory::~CodeFactory()
{
    delete factory;
}

void CodeFactory::AddClassUnit(std::string name, unsigned int flags)
{
    auto classInfo = classes.find(name);
    //If we add class again, it counts as add new class
    if(classInfo != classes.end() && classMethods.find(classInfo->second) != classMethods.end())
        classMethods.erase(classes.find(name)->second);
    classes[name] = factory->GetClassUnit(name, flags);
}

void CodeFactory::AddMethodUnit(std::string className, Unit::Flags accessType, std::string name, std::string returnType, Unit::Flags flags)
{
    auto classInfo = classes.find(className);
    if(classInfo == classes.end())
        throw std::runtime_error("Class not found!");
    if(classMethods.find(classInfo->second) == classMethods.end())
    {
        classMethods[classInfo->second] = std::vector<MethodInfo>();
    }
    auto newMethod = factory->GetMethodUnit(name, returnType, flags);
    classMethods[classInfo->second].push_back({name, newMethod});
    classes[className]->addSubUnit(newMethod, accessType);
}

void CodeFactory::AddPrintComand(std::string className, std::string methodName)
{
    auto classInfo = classes.find(className);
    if(classInfo == classes.end())
        throw std::runtime_error("Class not found!");
    auto methods = classMethods[classInfo->second];

    MethodPtr method = nullptr;
    for(auto info = methods.begin(); info != methods.end(); info++)
    {
        if(info->name == methodName)
        {
            method = info->ptr;
        }
    }
    if(method == nullptr)
        throw std::runtime_error("Method with given name not found!");
    method->addSubUnit(factory->GetPrintComand(), 0);
    return;
}

void CodeFactory::Compile()
{
    for(auto& e: classes)
        for(auto& str: e.second->Compile(0))
            writer->write(str);
}
