#pragma once

#include <vector>
#include <list>
#include <array>
#include <deque>
#include <iostream>
#include <algorithm>

class Span
{
private:
	size_t _max;
public:
	// Default constructor
	Span();

	// Parameterized constructor
	Span(unsigned int N);

	// Copy constructor
	Span(const Span& other);

	// Copy assignment operator
	Span& operator=(const Span& other);

	// Destructor
	~Span();

	/*
	This class will have a member function called addNumber() to add a single number
	to the Span. It will be used in order to fill it. Any attempt to add a new element if there
	are already N elements stored should throw an exception
	*/
	void addNumber();

	/*
	Next, implement two member functions: shortestSpan() and longestSpan()
	They will respectively find out the shortest span or the longest span (or distance, if
	you prefer) between all the numbers stored, and return it. If there are no numbers stored,
	or only one, no span can be found. Thus, throw an exception.
	*/
	size_t shortestSpan();
	size_t longestSpan();

};