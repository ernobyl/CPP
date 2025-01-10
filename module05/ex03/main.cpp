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
 	AForm*	rrf;
	try
	{
		rrf = someRandomIntern.makeForm("asdbery creation", "yard");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void test_form_robotomy()
{
	Intern	someRandomIntern;
 	AForm*	rrf;
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	test_form_exception();
	test_form_robotomy();
	
	return (0);
}