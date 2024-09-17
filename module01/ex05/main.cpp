#include "Harl.hpp"
#include <iostream>

int main(void)
{
    Harl harl;

    std::cout << "------Testing DEBUG:" << std::endl;
    harl.complain("DEBUG");
    std::cout << "------Testing INFO:" << std::endl;
    harl.complain("INFO");
    std::cout << "------Testing WARNING:" << std::endl;
    harl.complain("WARNING");
    std::cout << "------Testing ERROR:" << std::endl;
    harl.complain("ERROR");
    std::cout << "------Testing invalid (prints nothing):" << std::endl;
    harl.complain("WOLOLOO");
    return (0);
}