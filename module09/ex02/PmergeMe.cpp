#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& input) :
					_vec(input), _deq(input.begin(), input.end()),
					recursion_depth(0), comparison_count(0) {}


void PmergeMe::mergeSequencesVector(std::vector<int>& sorted, std::vector<int>& to_insert)
{
	for (int num : to_insert)
	{
		auto it = std::lower_bound(sorted.begin(), sorted.end(), num);
		comparison_count += std::distance(sorted.begin(), it); 
		sorted.insert(it, num);
	}
}

void PmergeMe::mergeSequencesDeque(std::deque<int>& sorted, std::deque<int>& to_insert)
{
	for (int num : to_insert)
	{
		auto it = std::lower_bound(sorted.begin(), sorted.end(), num);
		sorted.insert(it, num);
	}
}


void PmergeMe::sortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1) return;

	recursion_depth += 1;

	std::vector<std::pair<int, int>> pairs;
	std::vector<int> larger, smaller;

	size_t i = 0;
	while (i + 1 < arr.size())
	{
		if (arr[i] > arr[i + 1])
		{
			std::swap(arr[i], arr[i + 1]);
		}
		pairs.emplace_back(arr[i], arr[i + 1]);
		larger.push_back(arr[i + 1]);
		smaller.push_back(arr[i]);
		i += 2;
		comparison_count += 1;
	}

	// if odd element, keep it aside
	int oddElement = (arr.size() % 2 != 0) ? arr.back() : -1;

	// sort larger elements recursively
	sortVector(larger);

	// merge smaller elements
	std::vector<int> sorted = {larger[0]};
	mergeSequencesVector(sorted, smaller);

	// append remaining sorted larger elements
	for (size_t j = 1; j < larger.size(); ++j)
		sorted.push_back(larger[j]);

	// insert odd element
	if (oddElement != -1)
	{
		auto it = std::lower_bound(sorted.begin(), sorted.end(), oddElement);
		sorted.insert(it, oddElement);
	}

	arr = sorted;
}


void PmergeMe::sortDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1) return;

	std::deque<std::pair<int, int>> pairs;
	std::deque<int> larger, smaller;

	size_t i = 0;
	while (i + 1 < arr.size())
	{
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		pairs.emplace_back(arr[i], arr[i + 1]);
		larger.push_back(arr[i + 1]);
		smaller.push_back(arr[i]);
		i += 2;
	}

	int oddElement = (arr.size() % 2 != 0) ? arr.back() : -1;

	sortDeque(larger);

	std::deque<int> sorted = {larger[0]};
	mergeSequencesDeque(sorted, smaller);

	for (size_t j = 1; j < larger.size(); ++j)
		sorted.push_back(larger[j]);

	if (oddElement != -1)
	{
		auto it = std::lower_bound(sorted.begin(), sorted.end(), oddElement);
		sorted.insert(it, oddElement);
	}

	arr = sorted;
}


void PmergeMe::sortAndMeasure()
{
	auto start = std::chrono::high_resolution_clock::now();
	sortVector(_vec);
	auto end = std::chrono::high_resolution_clock::now();
	double duration_vec = std::chrono::duration<double, std::micro>(end - start).count();

	start = std::chrono::high_resolution_clock::now();
	sortDeque(_deq);
	end = std::chrono::high_resolution_clock::now();
	double duration_deq = std::chrono::duration<double, std::micro>(end - start).count();

	printAfter();
	std::cout << "Time to process with std::vector: " << duration_vec << " us" << std::endl;
	std::cout << "Time to process with std::deque: " << duration_deq << " us" << std::endl;
}

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (int num : _vec)
		std::cout << num << " ";
	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After: ";
	for (int num : _vec)
		std::cout << num << " ";
	std::cout << std::endl;
}
