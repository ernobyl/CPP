#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data		data{100, "Hello!"};
	Data*		data_ptr;
	uintptr_t	ptr;

	std::cout << data.i << std::endl;;
	std::cout << data.str << std::endl;;

	ptr = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(ptr);

	std::cout << &data << std::endl;
	std::cout << data_ptr << std::endl;

	std::cout << data_ptr->i << std::endl;;
	std::cout << data_ptr->str << std::endl;;

}