#pragma once

#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
	size_t			_max;
	size_t			_cur;
	std::set<int>	_set;
	bool			_hasDup;
public:
	// Default constructor
	Span() = delete;

	// Parameterized constructor
	Span(unsigned int N);

	// Copy constructor
	Span(const Span& other) = default;

	// Copy assignment operator
	Span& operator=(const Span& other) = default;

	// Destructor
	~Span() = default;

	/*
	This class will have a member function called addNumber() to add a single number
	to the Span. It will be used in order to fill it. Any attempt to add a new element if there
	are already N elements stored should throw an exception
	*/
	void	addNumber(int number);
	void	addNumber(int number, unsigned int n);
	void	addNumber(const std::vector<int>& vec);
	void	addNumber(std::vector<int>::const_iterator begin,
                           std::vector<int>::const_iterator end);
	void	addNumber(std::list<int>::const_iterator begin,
							std::list<int>::const_iterator end);
	/*
	Next, implement two member functions: shortestSpan() and longestSpan()
	They will respectively find out the shortest span or the longest span (or distance, if
	you prefer) between all the numbers stored, and return it. If there are no numbers stored,
	or only one, no span can be found. Thus, throw an exception.
	*/
	size_t shortestSpan() const;
	size_t longestSpan() const;

};