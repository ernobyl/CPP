#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap clappyboy("clappyboy");

    std::cout << "\033[33m↓    creating a new ScavTrap\033[0m" << std::endl;    
    ScavTrap scavvyboy("scavvyboy");
    std::cout << "\033[32m↑    ScavTrap created\033[0m" << std::endl;

    clappyboy.attack("enemy");
    clappyboy.attack("another enemy");
    scavvyboy.attack("");
    scavvyboy.attack("enemy");
    clappyboy.attack("enemy");
    clappyboy.attack("another enemy");
    clappyboy.attack("another enemy");
    scavvyboy.beRepaired(2);
    scavvyboy.takeDamage(5);
    scavvyboy.beRepaired(2);
    clappyboy.takeDamage(5);
    clappyboy.takeDamage(5);
    clappyboy.beRepaired(2);

    scavvyboy.guardGate();

    return (0);
}