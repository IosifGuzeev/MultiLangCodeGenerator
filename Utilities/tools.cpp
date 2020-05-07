#include <Utilities/tools.h>

std::vector<std::string> ReadAllLines(std::string path)
{
    std::vector<std::string> result;
    std::string line;
    std::ifstream infile(path);
    if(infile.is_open())
    {
        while(std::getline(infile, line))
            result.push_back(line);
    }
    return result;
}
