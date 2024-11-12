#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define HP_MAX_FRAG 100

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        // Default constructor
        FragTrap();
        FragTrap(std::string name);

        // Copy constructor
        FragTrap(const FragTrap& other);

        // Copy assignment operator
        FragTrap& operator=(const FragTrap& other);

        // Destructor
        ~FragTrap();

        void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
        void highFivesGuys();

};

#endif