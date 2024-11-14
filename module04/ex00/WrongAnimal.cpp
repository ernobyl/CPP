#include "WrongAnimal.hpp"
#include <iostream>

// constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
    std::cout << "WrongAnimal constructor called." << std::endl;
}

// destructor
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

// copy assignment operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}