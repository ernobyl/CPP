#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <regex>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double>	_data;
	void							loadDatabase(const std::string &database);
public:
	// Default constructor unnecessary
	BitcoinExchange() = delete;

	// Parameterized constructor
	BitcoinExchange(const std::string &database);

	// Copy constructor
	BitcoinExchange(const BitcoinExchange& other);

	// Copy assignment operator
	BitcoinExchange& operator=(const BitcoinExchange& other);

	// Destructor
	~BitcoinExchange() = default;

	void processInputFile(const std::string &inputFile) const;

};