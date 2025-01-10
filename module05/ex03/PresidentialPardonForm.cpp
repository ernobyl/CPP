#include <iostream>
#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() :
						AForm("PresidentialPardonForm", 25, 5),
						_target("default") {}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
						AForm("PresidentialPardonForm", 25, 5),
						_target(target)
{
	if (target.empty())
	throw std::invalid_argument("target name cannot be empty string");
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :  
						AForm(other), 
						_target(other._target) {}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return *this;
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Deleting PresidentialPardonForm for " << _target << std::endl;
}

// Function to print out presidential pardon
void PresidentialPardonForm::formAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}