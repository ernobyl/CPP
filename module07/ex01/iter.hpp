#pragma once

#include <cstddef>
#include <string>
#include <iostream>

template <typename T, typename Func>
void iter(T* array, std::size_t length, Func func)
{
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T>
void universalPrint(const T& value)
{
	std::cout << value << std::endl;
}

template <typename T>
void increment(T& x)
{
    ++x;
}
