#include <iostream>
#include "AForm.hpp"

// Default constructor
AForm::AForm() : _name("defaultform"), _signed(false), _grade_sign(150), _grade_exec(150) {}

// Parameterized constructor
AForm::AForm(const std::string& name, int grade_sign, int grade_exec) : _name(name), _signed(false)
{
	if (name.length() == 0)
		throw std::invalid_argument("name cannot be empty string");
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
	_grade_sign = grade_sign;
	_grade_exec = grade_exec;
}

// Copy constructor
AForm::AForm(const AForm& other) :
		_name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec) {}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return *this;
	_grade_sign = other._grade_sign;
	_grade_exec = other._grade_exec;
	_signed = other._signed;
	return *this;
}

// Destructor
AForm::~AForm()
{
	std::cout << "Deleting base form of " << _name << std::endl;
}

// Getters
const std::string& AForm::getName() const { return _name; }
int AForm::getSignGrade() const { return _grade_sign; }
int AForm::getExecGrade() const { return _grade_exec; }
bool AForm::getSigned() const { return _signed; }

/*
Member function that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a AForm::GradeTooLowException.
*/
void AForm::beSigned(Bureaucrat& signer)
{
	if (signer.getGrade() > _grade_sign)
		throw GradeTooLowException();
	else
		_signed = true;
}

/* 
Function to execute the form’s action of the concrete
classes. You have to check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
*/
void AForm::execute(Bureaucrat const& executor) const
{
	if (_signed == false)
		throw std::runtime_error("form not signed");
	if (executor.getGrade() > _grade_exec)
		throw GradeTooLowException();
	formAction();
}

/* 
Virtual function to perform whatever action the derived class needs to perform
*/
void AForm::formAction() const {}

// Exceptions
const char* AForm::GradeTooLowException::what() const throw ()
{
	return ("grade too low");
}

const char* AForm::GradeTooHighException::what() const throw ()
{
	return ("grade too high");
}

//  Insertion («) operator overload
std::ostream& operator<< (std::ostream& os, const AForm& form)
{
	os << "[ Form: " << form.getName() << std::endl
		<< "Grade required to sign: " << form.getSignGrade() << std::endl
		<< "Grade required to execute: " << form.getExecGrade() << std::endl;
	if (form.getSigned() == true)
		os << "Form is signed. ]";
	else
		os << "Form is not signed. ]";
	return os;
}