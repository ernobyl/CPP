#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat	John("John", 1);
	Bureaucrat	Paul("Paul", 100);
	Form		Study("Study form", 99);
	Form		Leave("Leave form", 130);


	std::cout << John << std::endl;
	std::cout << Paul << std::endl;
	std::cout << Study << std::endl;
	std::cout << Leave << std::endl;

	std::cout << "Try promoting John:" << std::endl;
	/* Increment throwing exception */
	try
	{
		John.rankUp();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Try demoting Paul:" << std::endl;
	/* Decrement */
	try
	{
		Paul.rankDown();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Testing form grade too high exception:" << std::endl;
	/* Form grade too high exception */
	try
	{
		Form	High("Highform", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Testing empty form name exception:" << std::endl;
	/* Form grade too high exception */
	try
	{
		Form	Nothing("", 5);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	Paul.signForm(Study);
	John.signForm(Study);

	return (0);
}