#include "HarlFilter.hpp"
#include <iostream>

int main(void)
{
    Harl harl;

    std::cout << "------Testing ERROR:" << std::endl;
    harl.complain("ERROR");
    std::cout << "------Testing INFO:" << std::endl;
    harl.complain("INFO");
    std::cout << "------Testing incorrect level:" << std::endl;
    harl.complain("fasdasdasd");
    return (0);
}
