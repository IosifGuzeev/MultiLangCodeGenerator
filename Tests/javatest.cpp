#include "javatest.h"

const std::vector<std::string> JavaTest::output_true_1 ={
                    "class A",
                    "{",
                    "    private int a()",
                    "    {",
                    "        System.out.println(\"Hello World!\");",
                    "    }",
                    "    protected void b()",
                    "    {",
                    "    }",
                    "};"
};

std::pair<bool, std::vector<std::string>> JavaTest::runTestCase1()
{
    auto logger = new VectorWriter();
    auto factory = CodeFactory(CodeFactory::java, logger);
    factory.AddClassUnit("A", 0);
    factory.AddMethodUnit("A", 1, "a", "int", 2);
    factory.AddMethodUnit("A", 2, "b", "void", 1);
    factory.AddPrintComand("A", "a");
    factory.Compile();

    auto output = logger->GetOutput();
    std::pair<bool, std::vector<std::string>> result = std::make_pair(true, std::vector<std::string>({""}));
    if(output.size() != output_true_1.size())
    {
        std::vector<std::string> messages;
        messages.push_back("Wrong lines count!");
        messages.push_back("Got: " + std::to_string(output.size()));
        messages.push_back("Expected: " + std::to_string(output_true_1.size()));
        result = std::make_pair(false, messages);
    }
    else
    {
        for(int i = 0; i < output_true_1.size(); i++)
        {
            if(output[i].compare(output_true_1[i]) != 0)
            {
                std::vector<std::string> messages;
                messages.push_back("Line " + std::to_string(i) + " is incorrect!");
                messages.push_back("Expected:");
                messages.insert(messages.end(), output_true_1.begin(), output_true_1.end());
                messages.push_back("Got:");
                messages.insert(messages.end(), output.begin(), output.end());

                result = std::make_pair(false, messages);
                break;
            }
        }
    }
    delete logger;
    return result;
}

void JavaTest::RunTests(Writer* output_logger)
{
    output_logger->write("Running tests for java langauge...");
    output_logger->write("");
    output_logger->write("Test case 1:");
    auto test_result = runTestCase1();
    if(test_result.first)
    {
        output_logger->write("Test passed!");
    }
    else
    {
        output_logger->write("Test failed!");
        output_logger->write("Message: ");
        for(auto &str: test_result.second)
            output_logger->write(str);
    }
    output_logger->write("");
    output_logger->write("Tests done");
    output_logger->write("");
    return;
}
