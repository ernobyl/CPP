#pragma once

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	int					_grade_sign;
	int					_grade_exec;
public:
	// Default constructor
	AForm();

	// Parameterized constructor
	AForm(const std::string& name, int grade_sign, int grade_exec);

	// Copy constructor
	AForm(const AForm& other);

	// Copy assignment operator
	AForm& operator=(const AForm& other);

	// Destructor
	virtual ~AForm();

	// Getters
	const std::string& getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;

	/*
	Member function that takes a Bureaucrat as
	parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
	(higher or equal to the required one). Remember, grade 1 is higher than grade 2.
	If the grade is too low, throw a AForm::GradeTooLowException.
	*/
	void beSigned(Bureaucrat& signer);

	/* 
	Function to execute the form’s action of the concrete
	classes. You have to check that the form is signed and that the grade of the bureaucrat
	attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
	*/
	void execute(Bureaucrat const& executor) const;

	/* 
	Virtual function to perform whatever action the derived class needs to perform
	*/
	virtual void formAction() const = 0;

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
std::ostream& operator<< (std::ostream& os, const AForm& form);