#pragma once

#include <string>
#include <iostream>
#include <map>

class DatesAndPrices
{
private:
	std::string                         _content;
	std::map<std::string, unsigned int> _data;
public:
	// Default constructor unnecessary
	DatesAndPrices() = delete;

	// Parameterized constructor
	DatesAndPrices(std::string database);

	// Copy constructor
	DatesAndPrices(const DatesAndPrices& other);

	// Copy assignment operator
	DatesAndPrices& operator=(const DatesAndPrices& other);

	// Destructor
	~DatesAndPrices() = default;

	std::map<std::string, unsigned int> parseDatabase(const std::string &database) const;

};