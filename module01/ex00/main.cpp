#include "Zombie.hpp"

int main(void)
{
    Zombie  *heapZombie = newZombie("Barry Heapzombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("Bertha Stackzombie");
    return (0);
}