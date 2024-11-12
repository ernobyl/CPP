#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap clappyboy("clappyboy");

    std::cout << "\033[33m↓    creating a new ScavTrap\033[0m" << std::endl;    
    ScavTrap scavvyboy("scavvyboy");
    std::cout << "\033[32m↑    ScavTrap created\033[0m" << std::endl;

    std::cout << "\033[33m↓    creating a new FragTrap\033[0m" << std::endl;    
    FragTrap fraggyboy("fraggyboy");
    std::cout << "\033[32m↑    FragTrap created\033[0m" << std::endl;

    fraggyboy.attack("enemy");
    fraggyboy.attack("another enemy");
    fraggyboy.attack("");
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
    
    fraggyboy.highFivesGuys();
    scavvyboy.guardGate();

    return (0);
}