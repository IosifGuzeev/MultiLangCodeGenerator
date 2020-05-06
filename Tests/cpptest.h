#ifndef CPPTEST_H
#define CPPTEST_H
#include <Factories/CppFactory/cppfactory.h>
#include <Utilities/writers.h>
class CppTest
{
    bool TestCase1()
    {
        return true;
    }
    CppTest();
public:
    void RunTests(Writer* writer)
    {
        return;
    }
};

#endif // CPPTEST_H
