#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string str) : name(str)
{}
Zombie::~Zombie()
{
    std::cout << name << " walked into the sea. Goodbye " << name << std::endl;
}

void    Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}