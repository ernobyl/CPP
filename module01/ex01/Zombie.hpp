#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string _name;
	
	public:
		Zombie(std::string str = "default");
		~Zombie();
        void    setName(std::string str);
		void	announce(void) const;
};

Zombie* zombieHorde(int N, std::string name);

#endif