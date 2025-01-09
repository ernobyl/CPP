#pragma once

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string	_target;
public:
	// Default constructor
	PresidentialPardonForm();

	// Parameterized constructor
	PresidentialPardonForm(std::string target);

	// Copy constructor
	PresidentialPardonForm(const PresidentialPardonForm& other);

	// Copy assignment operator
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	// Destructor
	~PresidentialPardonForm();

	// Function to print out presidential pardon
	void formAction() const override;

};