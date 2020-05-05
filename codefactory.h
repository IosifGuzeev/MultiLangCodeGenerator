#ifndef CODEFACTORY_H
#define CODEFACTORY_H
#include <Interfaces.h>
#include <Utilities/writers.h>


class CodeFactory
{
    AbstractFactory *factory;
    Writer *writer;


public:
    CodeFactory(){};

};

#endif // CODEFACTORY_H
