#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
    Weapon hammer("silver hammer");
    HumanA bob("Bob", hammer);
    bob.attack();
    hammer.setType("warhammer of a thousand screams +2");
    bob.attack();

    Weapon club("rock on stick");
    HumanB jim("Jim");
    jim.attack();
    jim.setWeapon(club);
    jim.attack();

    return 0;
}