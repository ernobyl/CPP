#include <iostream>
#include <fstream>
#include <string>
#include "replace_util.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string str1 = argv[2];
    std::string str2 = argv[3];

    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return (2);
    }
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    std::string newContent = replaceOccurrences(content, str1, str2);
    std::string outputFilename = "replace_" + filename;
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open())
    {
        std::cerr << "Could not create file: " << outputFilename << std::endl;
        return (2);
    }
    outputFile << newContent;
    outputFile.close();
    return (0);
}