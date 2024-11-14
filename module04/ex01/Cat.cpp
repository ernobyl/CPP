#include "Cat.hpp"
#include <iostream>

// constructor
Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called." << std::endl;
}

// destructor
Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called." << std::endl;
}

// copy constructor
Cat::Cat(const Cat &other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called." << std::endl;
}

// copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Breow!!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}
