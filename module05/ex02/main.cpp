#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat				John("John", 150);
	Bureaucrat				Paul("Paul", 10);
	Bureaucrat				Luke("Luke", 1);
	ShrubberyCreationForm	Yard("Yard");
	RobotomyRequestForm		Megatron("Megatron");
	PresidentialPardonForm	Joe("Killer Joe");

	std::cout << John << std::endl;
	std::cout << Paul << std::endl;
	std::cout << Luke << std::endl;
	std::cout << Yard << std::endl;
	std::cout << Megatron << std::endl;
	std::cout << Joe << std::endl;

	std::cout << "------Testing ShrubberyCreationForm------" << std::endl;
	Paul.executeForm(Yard);
	Paul.signForm(Yard);
	std::cout << Yard << std::endl;
	John.executeForm(Yard);
	Paul.executeForm(Yard);
	std::cout << "-----------------------------------------" << std::endl;
	
	std::cout << "------Testing RobotomyRequestForm--------" << std::endl;
	John.signForm(Megatron);
	Paul.signForm(Megatron);
	Paul.executeForm(Megatron);
	std::cout << "-----------------------------------------" << std::endl;

	std::cout << "------Testing PresidentialPardonForm-----" << std::endl;
	John.signForm(Joe);
	Paul.signForm(Joe);
	Paul.executeForm(Joe);
	Luke.executeForm(Joe);
	std::cout << "-----------------------------------------" << std::endl;
	return (0);
}