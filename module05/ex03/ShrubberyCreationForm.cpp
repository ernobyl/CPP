#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() :
						AForm("ShrubberyCreationForm", 145, 137),
						_target("default") {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
						AForm("ShrubberyCreationForm", 145, 137),
						_target(target)
{
	if (target.empty())
	throw std::invalid_argument("target name cannot be empty string");
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :  
						AForm(other), 
						_target(other._target) {}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Deleting ShrubberyCreationForm for " << _target << std::endl;
}

// Function to create shrubbery
void ShrubberyCreationForm::formAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile;
	outfile.open(filename);
	if (!outfile)
		throw std::runtime_error("file not found");
	else
	{
		outfile << "        @       \n";
		outfile << "  @ @  @@@   @  \n";
		outfile << " @@@@@@@@@@ @@@ \n";
		outfile << "@@@@@@@@@@@@@@` \n";
		outfile << " `@`@``@@@```|`@\n";
		outfile << "  | |   |    |/ \n";
		outfile << "  | |/  |    |  \n";
		outfile << ",,|,|,,,|,,,,|,,\n";
	}
}