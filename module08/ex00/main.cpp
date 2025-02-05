#include "easyfind.hpp"

void    test_vector()
{
    // Testing vector
    std::cout << "_____Testing vector:_____" << std::endl;
    std::vector<int>::iterator find;
    (void)find;
    std::vector<int> ints = {1, 2, 3, 4, 5, 6, 7};
    find = easyfind(ints, 3);
    find = easyfind(ints, 99);
    std::cout << "_________________________" << std::endl;
}

void test_list()
{
    // Testing list
    std::cout << "_____Testing list:_______" << std::endl;
    std::list<int>::const_iterator find;
    (void)find;
    const std::list<int> ints = {1, 2, 3, 4, 5, 6, 7};
    find = easyfind(ints, 4);
    find = easyfind(ints, 0);
    std::cout << "_________________________" << std::endl;
}

void test_array()
{
    // Testing array
    std::cout << "_____Testing array:______" << std::endl;
    const size_t size = 7;
    std::array<int, size>::iterator find;
    (void)find;
    std::array<int, size> ints = {1, 2, 3, 4, 5, 6, 7};
    find = easyfind(ints, 5);
    find = easyfind(ints, 9999);
    std::cout << "_________________________" << std::endl;
}

void test_deque()
{
    // Testing deque
    std::cout << "_____Testing deque:______" << std::endl;
    std::deque<int>::iterator find;
    (void)find;
    std::deque<int> ints = {1, 2, 3, 4, 5, 6, 7};
    find = easyfind(ints, 7);
    find = easyfind(ints, 99);
    std::cout << "_________________________" << std::endl;

}


int main(void)
{
    test_vector();
    test_list();
    test_array();
    test_deque();

    return 0;
}