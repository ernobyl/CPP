#include "Animal.hpp"
#include <iostream>

// constructor
Animal::Animal() : type("Animal") {}

// deconstructor
Animal::~Animal() {}

// copy constructor
Animal::Animal(const Animal &other)
{
    *this = other;
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
    std::cout << "unidentifiable snort" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}