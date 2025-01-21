#include "iter.hpp"

void	stringTest()
{
	std::string str_arr[] = {"Blue", "skies", "and", "golden", "sunshine"};
	std::size_t len = sizeof(str_arr)/sizeof(str_arr[0]);
	std::cout << "Print string array:" << std::endl;
	iter(str_arr, len, universalPrint<std::string>);
}

void	intTest()
{
	int int_arr[] = {1, 2, 3, 4, 5};
	std::size_t len = sizeof(int_arr)/sizeof(int_arr[0]);
	std::cout << "Print int array:" << std::endl;
	iter(int_arr, len, universalPrint<int>);
	iter(int_arr, len, increment<int>);
	std::cout << "Int array after incrementing each element:" << std::endl;
	iter(int_arr, len, universalPrint<int>);
}

int	main()
{
	stringTest();
	intTest();

	return 0;
}