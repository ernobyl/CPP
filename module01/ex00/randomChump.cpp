#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie  r_chump(name);
    r_chump.announce();
}