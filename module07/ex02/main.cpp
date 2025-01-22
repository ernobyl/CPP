#include <iostream>
#include "Array.hpp"

int	main()
{
	int size = 5;
	Array<int> intArray(size);
	for (int i = 0; i < size; i++)
	{
		intArray[i] = i;
		std::cout << intArray[i] << std::endl;
	}
	int getsize = intArray.size();
	std::cout << "size: " << getsize << std::endl;

	return 0;
}