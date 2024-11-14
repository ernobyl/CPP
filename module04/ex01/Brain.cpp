#include "Brain.hpp"
#include <iostream>

// constructor
Brain::Brain()
{
    std::cout << "Brain constructor called." << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "";
}

// destructor
Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}

// copy constructor
Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called." << std::endl;
    *this = other;
}

// copy assignment operator
Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int index) const
{
    return (index >= 0 && index < 100) ? _ideas[index] : "";
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}
