#include "Zombie.hpp"

int main(void)
{
    int N = 9;
    std::string name = "Spooky boy";

    Zombie  *horde = zombieHorde(N, name);
    if (horde)
    {
        for (int i = 0; i < N; ++i)
            horde[i].announce();
    }
    delete[] horde;
    return (0);
}