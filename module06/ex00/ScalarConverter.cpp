#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

bool ScalarConverter::_notInt = false;

bool	ScalarConverter::specialCase(const std::string& literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "inf"
		|| literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "inff")
		return true;
	else
		return false;
}

void	ScalarConverter::convert(const std::string& literal)
{
	if (literal.empty())
	{
		std::cerr << "Error: Empty literal." << std::endl;
		return;
	}
	if (specialCase(literal))
		_notInt = true;
	if (isCharLiteral(literal))
	{
		char c = literal[1];
		displayResults(static_cast<int>(c), c, static_cast<float>(c), static_cast<double>(c));
	}
	else if (isIntLiteral(literal))
	{
		try
		{
			int value = std::stoi(literal);
			displayResults(value, static_cast<char>(value), static_cast<float>(value), static_cast<double>(value));
		}
		catch (const std::out_of_range&)
		{
			std::cerr << "Error: Integer out of range." << std::endl;
		}
		catch (std::invalid_argument&)
		{
			std::cerr << "Error: Impossible" << std::endl;
		}
	}
	else if (isFloatLiteral(literal))
	{
		try 
		{
			float value = std::stof(literal);
			displayResults(static_cast<int>(value), static_cast<char>(value), value, static_cast<double>(value));
		}
		catch (const std::out_of_range&)
		{
			std::cerr << "Error: Float out of range." << std::endl;
		}
	}
	else if (isDoubleLiteral(literal))
	{
		try
		{
			double value = std::stod(literal);
			displayResults(static_cast<int>(value), static_cast<char>(value), static_cast<float>(value), value);
		}
		catch (const std::out_of_range&)
		{
			std::cerr << "Error: Double out of range." << std::endl;
		}
	}
	else
	 std::cerr << "Error: Unknown literal type." << std::endl;
	
}

bool ScalarConverter::isCharLiteral(const std::string& literal)
{
	return literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isIntLiteral(const std::string& literal)
{
	if (literal.find_first_not_of("-0123456789") != std::string::npos)
		return false;
	return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "inff")
		return true;
	if (literal.back() != 'f')
		return false;
	try
	{
		std::stof(literal);
		return true;
	}
	catch (...)
	{
		return false;
	}
}

bool ScalarConverter::isDoubleLiteral(const std::string& literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "inf")
		return true;
	try
	{
		std::stod(literal);
		return true;
	}
	catch (...)
	{
		return false;
	}
}

void ScalarConverter::displayResults(int i, char c, float f, double d)
{
	// Display char
	if (std::isprint(c))
	{
		std::cout << "char: '" << c << "'\n";
	}
	else
	{
		std::cout << "char: Non displayable\n";
	}

	// Display int
	if (_notInt == true)
		std::cout << "int: Non displayable\n";
	else
		std::cout << "int: " << i << "\n";

	// Display float
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";

	// Display double
	std::cout << "double: " << d << "\n";
}