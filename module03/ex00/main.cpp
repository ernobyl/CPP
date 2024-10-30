#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clappyboy("clappyboy");

    clappyboy.attack("enemy");
    clappyboy.attack("another enemy");
    clappyboy.attack("");
    clappyboy.attack("enemy");
    clappyboy.attack("enemy");
    clappyboy.attack("another enemy");
    clappyboy.attack("another enemy");
    clappyboy.beRepaired(2);
    clappyboy.takeDamage(5);
    clappyboy.beRepaired(2);
    clappyboy.beRepaired(2);
    clappyboy.beRepaired(2);
    clappyboy.takeDamage(5);
    clappyboy.takeDamage(5);
    clappyboy.beRepaired(2);

    return (0);
}