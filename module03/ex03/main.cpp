#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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

    std::cout << "\033[33m↓    creating a new FragTrap\033[0m" << std::endl;    
    FragTrap default_fraggyboy;
    std::cout << "\033[32m↑    FragTrap created\033[0m" << std::endl;

    std::cout << "\033[33m↓    creating a new DiamondTrap\033[0m" << std::endl;    
    DiamondTrap diamond("problemchild");
    std::cout << "\033[32m↑    DiamondTrap created\033[0m" << std::endl;

    std::cout << "\033[33m↓    creating a new DiamondTrap\033[0m" << std::endl;    
    DiamondTrap defaultdiamond;
    std::cout << "\033[32m↑    DiamondTrap created\033[0m" << std::endl;

    diamond.attack("");
    diamond.attack("itself");
    diamond.whoAmI();
    defaultdiamond.whoAmI();
    diamond.takeDamage(100);
    diamond.takeDamage(100);
    default_fraggyboy.highFivesGuys();
    fraggyboy.highFivesGuys();
    scavvyboy.guardGate();

    return (0);
}
