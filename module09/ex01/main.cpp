#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "argument required\n";
	}
	std::string argument = argv[1];
	try
	{
		int result;
		result = RPN::calc(argument);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}