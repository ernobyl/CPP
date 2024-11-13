#include "DiamondTrap.hpp"
#include <iostream>

// default constructor
DiamondTrap::DiamondTrap()
{
	this->_name = "default_diamond"; 
	ClapTrap::_name = "default_diamond_clap_name";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// parameterized constructor
DiamondTrap::DiamondTrap(std::string const &name)
{
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

// destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    *this = other;
}

// copy assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name + "_clap_name";
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    ScavTrap::takeDamage(amount);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My Diamond name is " << this->_name << " and my Clap name is " << ClapTrap::_name << std::endl;
}
