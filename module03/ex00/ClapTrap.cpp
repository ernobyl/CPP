#include "ClapTrap.hpp"
#include <iostream>

// default constructor
ClapTrap::ClapTrap()
    : _name("default claptrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{}

// parameterized constructor
ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{}

// destructor
ClapTrap::~ClapTrap()
{}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

// copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

void ClapTrap::attack(const std::string& target)
{
    if (target.empty())
    {
        std::cout << this->_name << " attacks the air for "
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

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0)
        this->_hitPoints = 0;
    std::cout << this->_name << " takes " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints != 0 && this->_hitPoints != 0 && this->_hitPoints < 10)
    {
        this->_hitPoints += amount;
        if (this->_hitPoints > 10)
            this->_hitPoints = 10;
        this->_energyPoints--;
        std::cout << this->_name << " is repaired for " << amount << " hitpoints." << std::endl;
    }
    else
        std::cout << this->_name << " can't be repaired." << std::endl;
}
