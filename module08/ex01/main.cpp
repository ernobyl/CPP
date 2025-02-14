#include "Span.hpp"
#include <random>

void vector_test()
{
	int size = 10000;
	Span sp = Span(size);
	std::vector<int> vec;
	for (int i = 0; i < size; ++i)
		vec.push_back(rand());
	std::random_shuffle(vec.begin(), vec.end());
	sp.addNumber(vec); // vector
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

}

void iterator_test()
{
	int size = 100000;
	Span sp = Span(size);
	std::vector<int> vec;
	for (int i = 0; i < size; ++i)
		vec.push_back(rand());
	sp.addNumber(vec.begin(), vec.end()); // iterators
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void iterator_test2()
{
	int size = 100000;
	Span sp = Span(size);
	std::list<int> lst;
	for (int i = 0; i < size; ++i)
		lst.push_back(rand());
	sp.addNumber(lst.begin(), lst.end()); // iterators
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void exceptions_test()
{
	Span sp = Span(1);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

void exceptions_test2()
{
	Span sp = Span(10);
	std::list<int> lst;
	for (int i = 0; i < 100; ++i)
		lst.push_back(rand());
	try
	{
		sp.addNumber(lst.begin(), lst.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void exceptions_test3()
{
	Span sp = Span(10);
	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	sp.addNumber(1);
	try
	{
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

void duplicate_test()
{
	Span sp = Span(7);
	sp.addNumber(6);
	sp.addNumber(3, 3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}


int main()
{
	srand(time(NULL));

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	vector_test();
	iterator_test();
	iterator_test2();
	exceptions_test();
	exceptions_test2();
	exceptions_test3();
	duplicate_test();

	return 0;
}