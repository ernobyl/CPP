#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int>    _vec;
	std::deque<int>     _deq;

	void                sortVector(std::vector<int>& arr);
	void                sortDeque(std::deque<int>& arr);

	// utility functions for merging sorted sequences
	void mergeSequencesVector(std::vector<int>& sorted, std::vector<int>& to_insert);
	void mergeSequencesDeque(std::deque<int>& sorted, std::deque<int>& to_insert);

public:
	// Default constructor
	PmergeMe() = delete;

	// Copy constructor
	PmergeMe(const PmergeMe& other) = delete;

	// Copy assignment operator
	PmergeMe& operator=(const PmergeMe& other) = delete;

	 // Constructor
	PmergeMe(const std::vector<int>& input);

	// Destructor
	~PmergeMe() = default;

	void sortAndMeasure();

	void printBefore() const;
	void printAfter() const;

	int recursion_depth;
	int comparison_count;

};