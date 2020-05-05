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
        std::runtime_error("Wrong language id!");
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
    classes[name] = factory->GetClassUnit(name, flags);
}

void CodeFactory::AddMethodUnit(std::string className, Unit::Flags accessType, std::string name, std::string returnType, Unit::Flags flags)
{
    if(classes.find(className) == classes.end())
        std::runtime_error("Class not found!");
    else
        classes[className]->addSubUnit(std::shared_ptr<Unit>(new CppMethodUnit(name, returnType, flags)), accessType);
}

void CodeFactory::Compile()
{
    for(auto& e: classes)
        for(auto& str: e.second->Compile(0))
            writer->write(str);
}
