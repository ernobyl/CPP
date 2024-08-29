#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string str) : name(str)
{}

Zombie::~Zombie()
{
    std::cout << name << " has left the chat" << std::endl;
}

void    Zombie::setName(std::string str)
{
    name = str;
}

void    Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}