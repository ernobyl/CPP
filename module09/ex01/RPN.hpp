#pragma once

#include <stack>
#include <string>
#include <stdexcept>
#include <limits>

class RPN
{
	public:
	// Default constructor
	RPN() = delete;
	// Copy constructor
	RPN(const RPN& other) = delete;
	// Copy assignment operator
	RPN& operator=(const RPN& other) = delete;
	// Destructor
	~RPN() = delete;
	
	static int	calc(const std::string &argument);
};