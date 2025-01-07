#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	// Default constructor
	Bureaucrat();

	// Parameterized constructor
	Bureaucrat(const std::string& name, int grade);

	// Copy constructor
	Bureaucrat(const Bureaucrat& other);

	// Copy assignment operator
	Bureaucrat& operator=(const Bureaucrat& other);

	// Destructor
	~Bureaucrat();

	// Rank incrementation and decrementation
	void	rankUp();
	void	rankDown();

	// Form signing function
	void	signForm(AForm& form);

	// Getters
	const std::string& getName() const;
	int getGrade() const;

	// Exceptions
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

//  Insertion («) operator overload
std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat);