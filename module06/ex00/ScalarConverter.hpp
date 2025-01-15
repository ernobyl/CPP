#pragma once

#include <string>

#define INVALID_CHAR -1
#define INVALID_INT 1000

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
	static char		c;
	static int		i;
	static float	f;
	static double	d;
	static void		convertCharLiteral(const std::string& literal);
	static void		convertIntLiteral(const std::string& literal);
	static void		convertFloatLiteral(const std::string& literal);
	static void		convertDoubleLiteral(const std::string& literal);
	static void		displayChar();
	static void		displayInt();
	static void		displayFloat();
	static void		displayDouble();
	static void		displayResults();
};
