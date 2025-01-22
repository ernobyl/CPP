#include <iostream>
#include "Array.hpp"

int	main()
{
	Array<int> intArray(5);
	for (int i = 0; i < intArray.size(); i++)
	{
		intArray[i] = i;
		std::cout << intArray[i] << std::endl;
	}
	std::cout << "size: " << intArray.size() << std::endl;

	Array<int> copyArray = intArray;
	copyArray[0] = 50;
	for (int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	for (int i = 0; i < copyArray.size(); i++)
		std::cout << copyArray[i] << std::endl;

	return 0;
}