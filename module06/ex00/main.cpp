#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        return 1;
    }

    std::string input = argv[1];
    ScalarConverter::convert(input);

    return 0;
}
