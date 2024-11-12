#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#define HP_MAX_SCAV 100

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        // Default constructor
        ScavTrap();
        ScavTrap(std::string name);

        // Copy constructor
        ScavTrap(const ScavTrap& other);

        // Copy assignment operator
        ScavTrap& operator=(const ScavTrap& other);

        // Destructor
        ~ScavTrap();

        void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
        void guardGate();

};

#endif