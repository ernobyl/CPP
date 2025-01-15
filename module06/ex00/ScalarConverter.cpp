#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <regex>

char	ScalarConverter::c;
int		ScalarConverter::i;
float	ScalarConverter::f;
double	ScalarConverter::d;

void	ScalarConverter::convert(const std::string& literal)
{
	if (literal.empty())
	{
		std::cerr << "Error: Empty literal." << std::endl;
		return;
	}
	std::regex int_("[-\\+]?\\d+");
	std::regex float_(R"(^([-+]?\d+\.\d*f|\d*\.\d+f|[-+]?\d+f|[-+]?\d+\.f|(-inf|\+inf|inf|nan)f)$)");
	std::regex double_(R"(^([-+]?\d+\.\d*|\d*\.\d+|[-+]?\d+\.|[-+]?\d+|(-inf|\+inf|inf|nan))$)");
	if (std::regex_match(literal, int_))
		convertIntLiteral(literal);
	else if (literal.length() == 1)
		convertCharLiteral(literal);
	else if (std::regex_match(literal, float_))
		convertFloatLiteral(literal);
	else if (std::regex_match(literal, double_))
		convertDoubleLiteral(literal);
	else
		std::cerr << "Error: Unknown literal type." << std::endl;
}

void ScalarConverter::convertCharLiteral(const std::string& literal)
{
	c = literal[0];
	i = c;
	f = c;
	d = c;
	displayResults();
}

void ScalarConverter::convertIntLiteral(const std::string& literal)
{
	try
	{
		i = std::stoi(literal);
		c = i >= 0 && i <= 127 ? static_cast<char>(i) : -1;
		f = i;
		d = i;
		displayResults();
  	}
  	catch (std::out_of_range& e)
	{
    	convertFloatLiteral(literal);
  	}
}

void ScalarConverter::convertFloatLiteral(const std::string& literal)
{
	try
	{
		f = std::stof(literal);
		d = f;
		if ((d > 0.0 && d - std::numeric_limits<int>::max() >= 1.0) ||
			(d < 0.0 && d - std::numeric_limits<int>::min() <= -1.0))
		{
			c = INVALID_CHAR;
			i = INVALID_INT;
		}
		else
		{
			i = static_cast<int>(f);
			c = i >= 0 && i <= 127 ? static_cast<char>(i) : -1;
		}
		displayResults();
  }
  	catch (std::out_of_range& e)
	{
    	convertDoubleLiteral(literal);
  	}
}

void ScalarConverter::convertDoubleLiteral(const std::string& literal)
{
	try
	{
		d = std::stod(literal);
		if (!std::isinf(d) &&
			((d > 0.0 && d - std::numeric_limits<float>::max() >= 1.0) ||
			(d < 0.0 && d - std::numeric_limits<float>::lowest() <= -1.0)))
		{
			c = INVALID_CHAR;
			i = INVALID_INT;
			f = std::numeric_limits<float>::max();
   		}
		else if ((d > 0.0f && d - std::numeric_limits<int>::max() >= 1.0) ||
               (d < 0.0f && d - std::numeric_limits<int>::min() <= -1.0))
		{
			c = INVALID_CHAR;
			i = INVALID_INT;
			f = static_cast<float>(d);
    	}
		else
		{
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			c = i >= 0 && i <= 127 ? static_cast<char>(i) : -1;
    	}
    displayResults();
  }
  catch (std::out_of_range& e)
  {
		std::cout << "char: impossible\n" << "int: impossible\n"
				<< "float: impossible\n" << "double: impossible\n";
  }
}

void ScalarConverter::displayChar()
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
	{
		std::cout << "char: "
              << (i >= 0 && i <= 127 ? "Non displayable" : "impossible") << '\n';
	}
}

void ScalarConverter::displayInt()
{
	if ((d > 0.0 && d - std::numeric_limits<int>::max() >= 1.0) ||
    	(d < 0.0 && d - std::numeric_limits<int>::min() <= -1.0) ||
		(std::isnan(d)))
		std::cout << "int: impossible\n";
	else
    	std::cout << "int: " << i << '\n';
}

void ScalarConverter::displayFloat()
{
	if (!std::isinf(d) &&
      ((d > 0.0 && d - std::numeric_limits<float>::max() >= 1.0) ||
       (d < 0.0 && d - std::numeric_limits<float>::lowest() <= -1.0)))
    	std::cout << "float: impossible\n";
  	else
    	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
}

void ScalarConverter::displayDouble()
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << '\n';
}

void ScalarConverter::displayResults()
{
	displayChar();
	displayInt();
	displayFloat();
	displayDouble();
}