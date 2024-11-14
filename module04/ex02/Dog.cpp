#include "Dog.hpp"
#include <iostream>

// constructor
Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called." << std::endl;
}

// destructor
Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called." << std::endl;
}

// copy constructor
Dog::Dog(const Dog &other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called." << std::endl;
}

// copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return brain;
}
