#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string str) : _name(str)
{}

Zombie::~Zombie()
{
    std::cout << _name << " has left the chat" << std::endl;
}

void    Zombie::setName(std::string str)
{
    _name = str;
}

void    Zombie::announce(void) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}