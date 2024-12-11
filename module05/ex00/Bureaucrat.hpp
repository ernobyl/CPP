#pragma once

#include <string>
#include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	// Default constructor
	Bureaucrat();

	// Parameterized constructor
	Bureaucrat(std::string& name, int grade);

	// Copy constructor
	Bureaucrat(const Bureaucrat& other);

	// Copy assignment operator
	Bureaucrat& operator=(const Bureaucrat& other);

	// Destructor
	~Bureaucrat();

	class GradeTooLowException : std::exception
	{
		public:
			const char* what() const throw() override;
	};

	class GradeTooHighException : std::exception
	{
		public:
			const char* what() const throw() override;
	};
};