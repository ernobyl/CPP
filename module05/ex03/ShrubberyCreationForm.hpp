#pragma once

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;
public:
	// Default constructor
	ShrubberyCreationForm();

	// Parameterized constructor
	ShrubberyCreationForm(std::string target);

	// Copy constructor
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	// Copy assignment operator
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	// Destructor
	~ShrubberyCreationForm();

	// Function to create shrubbery
	void formAction() const override;

};