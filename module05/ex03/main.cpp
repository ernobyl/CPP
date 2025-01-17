#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void test_form_exception()
{
	Intern	someRandomIntern;
 	AForm*	rf;
	try
	{
		rf = someRandomIntern.makeForm("asdbery creation", "yard");
		std::cout << *rf << std::endl;
		delete rf;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test_form_robotomy()
{
	Intern		someRandomIntern;
 	AForm*		rf;
	Bureaucrat	Mary("Mary", 2);
	Bureaucrat	John("John", 146);
	try
	{
		rf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rf << std::endl;
		std::cout << Mary << std::endl;
		std::cout << John << std::endl;
		John.signForm(*rf);
		Mary.signForm(*rf);
		Mary.executeForm(*rf);
		delete rf;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test_form_shrubbery()
{
	Intern	someRandomIntern;
 	AForm*	rf;
	Bureaucrat	Mary("Mary", 2);
	try
	{
		rf = someRandomIntern.makeForm("shrubbery creation", "backyard");
		std::cout << *rf << std::endl;
		Mary.signForm(*rf);
		Mary.executeForm(*rf);
		delete rf;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test_form_pardon()
{
	Intern	someRandomIntern;
 	AForm*	rf;
	Bureaucrat	Mary("Mary", 2);
	try
	{
		rf = someRandomIntern.makeForm("presidential pardon", "Murderin' Mike");
		std::cout << *rf << std::endl;
		Mary.signForm(*rf);
		Mary.executeForm(*rf);
		delete rf;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	test_form_exception();
	test_form_robotomy();
	test_form_shrubbery();
	test_form_pardon();
	
	return (0);
}