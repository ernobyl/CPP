#pragma once

#include <vector>
#include <list>
#include <array>
#include <deque>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int num)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
    {
        std::cerr << "Could not find integer " << num << " in container." << std::endl;
        return {};
    }
    std::cout << "Found: " << *it << " at index: " << std::distance(container.begin(), it) << std::endl;
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int num)
{
    typename T::const_iterator it;
    it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
    {
        std::cerr << "Could not find integer " << num << " in container." << std::endl;
        return {};
    }
    std::cout << "Found: " << *it << " at index: " << std::distance(container.begin(), it) << std::endl;
    return it;
}
