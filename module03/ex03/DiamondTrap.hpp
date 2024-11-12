#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        // Default constructor
        DiamondTrap();
        DiamondTrap(std::string name);

        // Copy constructor
        DiamondTrap(const DiamondTrap& other);

        // Copy assignment operator
        DiamondTrap& operator=(const DiamondTrap& other);

        // Destructor
        virtual ~DiamondTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
		void whoAmI();

};

#endif