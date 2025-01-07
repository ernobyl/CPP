#pragma once

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	int					_grade_req;
public:
	// Default constructor
	Form();

	// Parameterized constructor
	Form(const std::string& name, int grade_req);

	// Copy constructor
	Form(const Form& other);

	// Copy assignment operator
	Form& operator=(const Form& other);

	// Destructor
	~Form();

	// Getters
	const std::string& getName() const;
	int getGrade() const;
	bool getSigned() const;

	/*
	Member function that takes a Bureaucrat as
	parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
	(higher or equal to the required one). Remember, grade 1 is higher than grade 2.
	If the grade is too low, throw a Form::GradeTooLowException.
	*/
	void beSigned(Bureaucrat& signer);

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
std::ostream& operator<< (std::ostream& os, const Form& form);