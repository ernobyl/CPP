#pragma once

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string	_target;
public:
	// Default constructor
	RobotomyRequestForm();

	// Parameterized constructor
	RobotomyRequestForm(std::string target);

	// Copy constructor
	RobotomyRequestForm(const RobotomyRequestForm& other);

	// Copy assignment operator
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	// Destructor
	~RobotomyRequestForm();

	// Function to perform robotomy
	void formAction() const override;

};