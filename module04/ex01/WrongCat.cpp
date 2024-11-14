#include "WrongCat.hpp"
#include <iostream>

// constructor
WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called." << std::endl;
}

// destructor
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called." << std::endl;
}

// copy constructor
WrongCat::WrongCat(const WrongCat &other)
{
    *this = other;
    std::cout << "WrongCat copy constructor called." << std::endl;
}

// copy assignment operator
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Gronk?" << std::endl;
}
