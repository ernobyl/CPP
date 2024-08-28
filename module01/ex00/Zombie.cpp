#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string str) : name(str)
{}
Zombie::~Zombie()
{}

void    Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}