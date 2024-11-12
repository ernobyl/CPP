#include "DiamondTrap.hpp"
#include <iostream>

// default constructor
DiamondTrap::DiamondTrap() : ClapTrap("default diamondtrap_clap_trap")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "default diamondtrap";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

// parameterized constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	this->_name = name;
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
        this->_name = other._name + "_clap_trap";
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