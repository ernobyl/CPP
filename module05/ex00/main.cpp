#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat	John("John", 1);
	Bureaucrat	Paul("Paul", 150);

	std::cout << John << std::endl;
	std::cout << Paul << std::endl;

	std::cout << "\nTry creating Peter with grade 0" << std::endl;
	/* GradeTooHighException */
	try
	{
		Bureaucrat Peter("Peter", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nTry creating Luke with grade 151" << std::endl;
	/* GradeTooLowException */
	try
	{
		Bureaucrat Luke("Luke", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nTry promoting John:" << std::endl;
	/* Increment throwing exception */
	try
	{
		John.rankUp();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nTry demoting Paul:" << std::endl;
	/* Decrement throwing exception */
	try
	{
		Paul.rankDown();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}