#include "Zombie.hpp"
#include <iostream>

Zombie  *zombieHorde(int N, std::string name)
{
	if (N <= 1)
	{
		std::cout << "Need more zombies for a horde" << std::endl;
		return (NULL);
	}
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		horde[i].setName(name);
	}
	return (horde);
}