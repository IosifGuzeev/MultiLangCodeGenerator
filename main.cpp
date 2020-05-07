#include <QCoreApplication>
#include <codefactory.h>
#include <Utilities/writers.h>
#include <Tests/cpptest.h>
#include <Tests/javatest.h>
#include <Tests/csharptest.h>

int main(int argc, char *argv[])
{
    auto consoleWriter = new ConsoleWriter();
    CppTest::RunTests(consoleWriter);
    JavaTest::RunTests(consoleWriter);
    CSharpTest::RunTests(consoleWriter);
}
