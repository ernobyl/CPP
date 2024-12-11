#include "Bureaucrat.hpp"
#include <iostream>

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string& name, int grade) : _name(name)
{
	if (name.length() == 0)
		throw std::invalid_argument("name cannot be empty string");
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	grade = _grade;
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("grade too high");
}