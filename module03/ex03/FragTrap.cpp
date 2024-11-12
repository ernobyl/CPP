#include "FragTrap.hpp"
#include <iostream>

// default constructor
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "default scavtrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap()
{
	std::cout << "FragTrap parameterized constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

// copy constructor
FragTrap::FragTrap(const FragTrap &other)
{
    *this = other;
}

// copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other)
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

void FragTrap::attack(const std::string& target)
{
    if (target.empty())
    {
        std::cout << this->_name << " attacks imaginary mosquitoes for "
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

void FragTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0)
        this->_hitPoints = 0;
    std::cout << this->_name << " takes " << amount << " damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints != 0 && this->_hitPoints != 0 && this->_hitPoints < HP_MAX_FRAG)
    {
        this->_hitPoints += amount;
        if (this->_hitPoints > HP_MAX_FRAG)
            this->_hitPoints = HP_MAX_FRAG;
        this->_energyPoints--;
        std::cout << this->_name << " is repaired for " << amount << " hitpoints." << std::endl;
    }
    else
        std::cout << this->_name << " can't be repaired." << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " requests the highest of fives!" << std::endl;
}
