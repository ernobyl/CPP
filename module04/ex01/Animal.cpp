#include "Animal.hpp"
#include <iostream>

// constructor
Animal::Animal() : type("Animal") 
{
    std::cout << "Animal constructor called." << std::endl;
}

// destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

// copy constructor
Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Animal copy constructor called." << std::endl;
}

// copy assignment operator
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}