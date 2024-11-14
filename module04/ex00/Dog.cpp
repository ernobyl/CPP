#include "Dog.hpp"
#include <iostream>

// constructor
Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called." << std::endl;
}

// destructor
Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
}

// copy constructor
Dog::Dog(const Dog &other)
{
    *this = other;
    std::cout << "Dog copy constructor called." << std::endl;
}

// copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
