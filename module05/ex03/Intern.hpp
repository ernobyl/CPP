#pragma once

#include <string>
#include "AForm.hpp"

class Aform;

class Intern
{
public:
	// Default constructor
	Intern();

	// Copy constructor
	Intern(const Intern& other);

	// Copy assignment operator
	Intern& operator=(const Intern& other);

	// Destructor
	~Intern();

	int	selectFormType(const std::string& name);

	/*
	Function that takes two strings as parameters. 
	The first one is the name of a form and the second one is the target of the
	form. It returns a pointer to a Form object (whose name is the one passed as parameter)
	whose target will be initialized to the second parameter
	*/
	AForm* makeForm(const std::string& name, const std::string& target);

	class FormDoesntExistException : public std::exception
	{
		public:
    		const char* what() const throw();
	};
};
