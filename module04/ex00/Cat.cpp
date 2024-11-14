#include "Cat.hpp"
#include <iostream>

// constructor
Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

// destructor
Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
}

// copy constructor
Cat::Cat(const Cat &other)
{
    *this = other;
    std::cout << "Cat copy constructor called." << std::endl;
}

// copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Breow!!" << std::endl;
}
