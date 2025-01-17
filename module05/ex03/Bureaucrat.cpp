#include "Bureaucrat.hpp"
#include <iostream>

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (name.length() == 0)
		throw std::invalid_argument("name cannot be empty string");
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	_grade = other._grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat " << _name << " deleted." << std::endl;
}

// Rank incrementation and decrementation
void	Bureaucrat::rankUp()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
	{
		_grade--;
		std::cout << "Bureaucrat " << _name << " promoted to rank " << _grade << std::endl;
	}
}

void	Bureaucrat::rankDown()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
	{
		_grade++;
		std::cout << "Bureaucrat " << _name << " demoted to rank " << _grade << std::endl;
	}
}

// Form signing function
void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed form: " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't sign form " << form.getName() << ". Reason: " << e.what() << std::endl;
	}
}

// Form execution function
void	Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed form: " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << _name << " couldn't execute form " << form.getName() << ". Reason: " << e.what() << std::endl;
	}
}

// Getters
const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

// Exceptions
const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("grade too high");
}

//  Insertion («) operator overload
std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "Bureaucrat " << bureaucrat.getName() << " grade: " << bureaucrat.getGrade();
	return os;
}