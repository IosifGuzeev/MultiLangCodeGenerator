#ifndef WRITERS_H
#define WRITERS_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Writer
{
public:
    virtual void write(std::string msg) = 0;
    virtual ~Writer() = default;
};

class ConsoleWriter : public Writer
{
public:
    ConsoleWriter(){};
    void write(std::string msg) override;
};

class FileWriter : public Writer
{
    std::string outputPath;
public:
    FileWriter(std::string _outputPath):outputPath(_outputPath) {};
    void write(std::string) override;
};

class VectorWriter : public Writer
{
    std::vector<std::string> output;

    // Writer interface
public:
    void write(std::string msg) override;
    std::vector<std::string> GetOutput();
};

#endif // WRITERS_H
