#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Default constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern& other) {}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other) { return *this; }

// Destructor
Intern::~Intern() {}

int	Intern::selectFormType(const std::string& name)
{
	std::string	formType[3] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	for (int i = 0; i < 3; i++)
	{
		if (formType[i] == name)
			return i;
	}
	return -1;
}

/*
	Function that takes two strings as parameters. 
	The first one is the name of a form and the second one is the target of the
	form. It return a pointer to a Form object (whose name is the one passed as parameter)
	whose target will be initialized to the second parameter
*/
AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	int		type = selectFormType(name);
	AForm	*out;
	switch (type)
	{
	case 0:
		out = new PresidentialPardonForm(target);
		break;
	case 1:
		out = new RobotomyRequestForm(target);
		break;
	case 2:
		out = new ShrubberyCreationForm(target);
		break;
	default:
		throw Intern::FormDoesntExistException();
	}
	std::cout << "Intern created " << name << " form." << std::endl;
	return out;
}

const char* Intern::FormDoesntExistException::what() const throw ()
{
	return ("Form doesn't exist.");
}