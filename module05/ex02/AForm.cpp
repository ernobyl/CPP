#include <iostream>
#include "AForm.hpp"

// Default constructor
AForm::AForm() : _name("defaultform"), _signed(false), _grade_req(150) {}

// Parameterized constructor
AForm::AForm(const std::string& name, int grade_req) : _name(name), _signed(false)
{
	if (name.length() == 0)
		throw std::invalid_argument("name cannot be empty string");
	if (grade_req < 1)
		throw GradeTooHighException();
	else if (grade_req > 150)
		throw GradeTooLowException();
	_grade_req = grade_req;
}

// Copy constructor
AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _grade_req(other._grade_req) {}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return *this;
	_grade_req = other._grade_req;
	_signed = other._signed;
	return *this;
}

// Destructor
AForm::~AForm()
{
	std::cout << "Deleting form " << _name << std::endl;
}

// Getters
const std::string& AForm::getName() const
{
	return _name;
}
int AForm::getGrade() const
{
	return _grade_req;
}
bool AForm::getSigned() const
{
	return _signed;
}

/*
Member function that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a AForm::GradeTooLowException.
*/
void AForm::beSigned(Bureaucrat& signer)
{
	if (signer.getGrade() > _grade_req)
		throw GradeTooLowException();
	else
		_signed = true;
}

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
	os << "[ AForm: " << form.getName() << std::endl
		<< "Grade required: " << form.getGrade() << std::endl;
	if (form.getSigned() == true)
		os << "AForm is signed. ]";
	else
		os << "AForm is not signed. ]";
	return os;
}