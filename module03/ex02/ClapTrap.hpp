#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define HP_MAX_CLAP 10

#include <string>

class ClapTrap
{
    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;
    public:
        // Default constructor
        ClapTrap();
        ClapTrap(std::string name);

        // Copy constructor
        ClapTrap(const ClapTrap& other);

        // Copy assignment operator
        ClapTrap& operator=(const ClapTrap& other);

        // Destructor
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif