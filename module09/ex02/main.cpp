#include "PmergeMe.hpp"
#include <set>

bool is_positive_integer(const std::string& str)
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

bool has_duplicates(const std::vector<int>& numbers)
{
    std::set<int> unique_nums(numbers.begin(), numbers.end());
    return unique_nums.size() != numbers.size();
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Error: No numbers provided." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    for (int i = 1; i < argc; i++)
    {
        if (!is_positive_integer(argv[i]))
        {
            std::cout << "Error: Invalid input detected." << std::endl;
            return 1;
        }
        numbers.push_back(std::stoi(argv[i]));
    }

    if (has_duplicates(numbers))
    {
        std::cout << "Error: Duplicate values found." << std::endl;
        return 1;
    }

    PmergeMe sorter(numbers);
    sorter.printBefore();
    sorter.sortAndMeasure();
    std::cout << "Vector: recursion depth: " << sorter.recursion_depth << std::endl;
    std::cout << "Vector: comparison count: " << sorter.comparison_count << std::endl;

    return 0;
}
