#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

int	main()
{
	unsigned int	len = 6;
	Array<int> intArray(len);
	for (unsigned int i = 0; i < intArray.size(); i++)
	{
		intArray[i] = i;
		std::cout << intArray[i] << std::endl;
	}
	std::cout << "size: " << intArray.size() << std::endl;

	Array<int> copyArray = intArray;
	copyArray[0] = 50;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	for (unsigned int i = 0; i < copyArray.size(); i++)
		std::cout << copyArray[i] << std::endl;

	try
	{
		intArray[-1] = 100;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		intArray[len] = 100;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}