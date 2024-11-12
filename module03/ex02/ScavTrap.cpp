#include "ScavTrap.hpp"
#include <iostream>

// default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "default scavtrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap &other)
{
    *this = other;
}

// copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (target.empty())
    {
        std::cout << this->_name << " attacks nothing for "
            << this->_attackDamage << " damage." << std::endl;
    }
    else if (this->_energyPoints != 0 && this->_hitPoints != 0)
    {
        std::cout << this->_name << " attacks " << target << " for "
            << this->_attackDamage << " damage." << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << this->_name << " can't do anything." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0)
        this->_hitPoints = 0;
    std::cout << this->_name << " takes " << amount << " damage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints != 0 && this->_hitPoints != 0 && this->_hitPoints < HP_MAX_SCAV)
    {
        this->_hitPoints += amount;
        if (this->_hitPoints > HP_MAX_SCAV)
            this->_hitPoints = HP_MAX_SCAV;
        this->_energyPoints--;
        std::cout << this->_name << " is repaired for " << amount << " hitpoints." << std::endl;
    }
    else
        std::cout << this->_name << " can't be repaired." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
