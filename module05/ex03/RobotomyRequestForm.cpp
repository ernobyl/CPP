#include <iostream>
#include <random>
#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() :
						AForm("RobotomyRequestForm", 72, 45),
						_target("default") {}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
						AForm("RobotomyRequestForm", 72, 45),
						_target(target)
{
	if (target.empty())
	throw std::invalid_argument("target name cannot be empty string");
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :  
						AForm(other), 
						_target(other._target) {}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Deleting RobotomyRequestForm for " << _target << std::endl;
}

// Function to perform robotomy
void RobotomyRequestForm::formAction() const
{
	std::cout << "*~DRILLING NOISES~*" << std::endl;
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);
	if (dist(gen) == 0)
		std::cout << "Robotomy on " << _target << " failed." << std::endl;
	else
		std::cout << _target << " robotomized succesfully!" << std::endl;
}