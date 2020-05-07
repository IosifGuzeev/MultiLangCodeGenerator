#ifndef JAVATEST_H
#define JAVATEST_H
#include <Factories/CppFactory/cppfactory.h>
#include <codefactory.h>
#include <Utilities/writers.h>
#include <fstream>


class JavaTest
{
    static const std::vector<std::string> output_true_1;

    static std::pair<bool, std::vector<std::string>> runTestCase1();

    JavaTest(){};
public:
    static void RunTests(Writer* output_logger);
};


#endif // JAVATEST_H
