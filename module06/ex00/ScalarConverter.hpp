#pragma once

#include <string>

class ScalarConverter
{
public:
	// Default constructor
	ScalarConverter() = delete;

	// Copy constructor
	ScalarConverter(const ScalarConverter& other) = delete;

	// Copy assignment operator
	ScalarConverter& operator=(const ScalarConverter& other) = delete;

	// Destructor
	~ScalarConverter();

	static void	convert(const std::string& literal);

private:
	static bool	_notInt;
	static bool	isCharLiteral(const std::string& literal);
	static bool	isIntLiteral(const std::string& literal);
	static bool	isFloatLiteral(const std::string& literal);
	static bool	isDoubleLiteral(const std::string& literal);
	static void	displayResults(int i, char c, float f, double d);
	static bool	specialCase(const std::string& literal);
	
};
