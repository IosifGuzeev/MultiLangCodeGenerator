#ifndef CSHARPTEST_H
#define CSHARPTEST_H

#include <Factories/CSharpFactory/csharpfactory.h>
#include <codefactory.h>
#include <Utilities/writers.h>
#include <fstream>


class CSharpTest
{
    static const std::vector<std::string> output_true_1;

    static std::pair<bool, std::vector<std::string>> runTestCase1();

    CSharpTest(){};
public:
    static void RunTests(Writer* output_logger);
};

#endif // CSHARPTEST_H
