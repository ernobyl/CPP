#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string str) : _name(str)
{}
Zombie::~Zombie()
{
    std::cout << _name << " walked into the sea. Goodbye " << _name << std::endl;
}

void    Zombie::announce(void) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}