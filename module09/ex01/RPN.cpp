#include "RPN.hpp"

int run_operation(char o, std::stack<long> &nums)
{
    if (nums.size() < 2)
        throw std::runtime_error("not enough operands for calculation");

    long b = nums.top(); nums.pop();
    long a = nums.top(); nums.pop();
    long result = 0;

    if (o == '+')
        result = a + b;
    else if (o == '-')
        result = a - b;
    else if (o == '*')
        result = a * b;
    else if (o == '/')
    {
        if (b == 0)
            throw std::runtime_error("division by zero");
        result = a / b;
    }
    if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max())
        throw std::runtime_error("integer overflow");
    return result;
}


int RPN::calc(const std::string &argument)
{
    std::stack<long> nums;
    std::string operators = "+-*/";
    long result = 0;

    if (argument.empty())
        throw std::runtime_error("empty argument");

    for (size_t i = 0; i < argument.length(); i++)
    {
        char c = argument[i];

        if (c == ' ') 
            continue;

        if (!std::isdigit(c) && operators.find(c) == std::string::npos)
            throw std::runtime_error("argument contains invalid character");

		if (c == '-' && i + 1 < argument.length() && std::isdigit(argument[i + 1]))
		{
			nums.push(-(argument[i + 1] - '0'));
			i++;
		}
        else if (std::isdigit(c))
        {
            if (i + 1 < argument.length() && std::isdigit(argument[i + 1]))
                throw std::runtime_error("argument contains multi-digit number");

            nums.push(c - '0');
        }
        else if (operators.find(c) != std::string::npos)
        {
            if (nums.size() < 2)
                throw std::runtime_error("not enough operands for calculation");
            result = run_operation(c, nums);
            nums.push(result);
        }
    }

    if (nums.size() != 1)
        throw std::runtime_error("invalid RPN expression");

    return nums.top();
}
