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

void	doubleTest()
{
	double double_arr[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
	std::size_t len = sizeof(double_arr)/sizeof(double_arr[0]);
	std::cout << "Print double array:" << std::endl;
	iter(double_arr, len, universalPrint<double>);
	iter(double_arr, len, increment<double>);
	std::cout << "double array after incrementing each element:" << std::endl;
	iter(double_arr, len, universalPrint<double>);
}

void	floatTest()
{
	float float_arr[] = {0.20f, 0.30f, 0.40f, 0.50f, 0.60f};
	std::size_t len = sizeof(float_arr)/sizeof(float_arr[0]);
	std::cout << "Print float array:" << std::endl;
	iter(float_arr, len, universalPrint<float>);
	iter(float_arr, len, increment<float>);
	std::cout << "float array after incrementing each element:" << std::endl;
	iter(float_arr, len, universalPrint<float>);
}

int	main()
{
	stringTest();
	intTest();
	doubleTest();
	floatTest();

	return 0;
}