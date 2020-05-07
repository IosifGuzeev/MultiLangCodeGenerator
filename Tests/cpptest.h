#ifndef CPPTEST_H
#define CPPTEST_H
#include <Factories/CppFactory/cppfactory.h>
#include <codefactory.h>
#include <Utilities/writers.h>
#include <fstream>


class CppTest
{
    static const std::vector<std::string> output_true_1;

    static std::pair<bool, std::vector<std::string>> runTestCase1();

    CppTest(){};
public:
    static void RunTests(Writer* output_logger);
};

#endif // CPPTEST_H
