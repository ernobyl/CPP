#include "PmergeMe.hpp"
#include <set>
#include <cmath>

bool is_positive_integer(const std::string& str)
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

bool has_duplicates(const std::vector<int>& numbers)
{
    std::set<int> unique_nums(numbers.begin(), numbers.end());
    return unique_nums.size() != numbers.size();
}

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Error: No numbers provided." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int num_count = 0;
    for (int i = 1; i < argc; i++)
    {
        if (!is_positive_integer(argv[i]))
        {
            std::cout << "Error: Invalid input detected." << std::endl;
            return 1;
        }
        num_count++;
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
    std::cout << "expected comparison count: under " << F(num_count) << std::endl;

    return 0;
}
