#include "Span.hpp"

Span::Span(unsigned int N) : _max(N), _cur(0), _hasDup(false) {}

void Span::addNumber(int number)
{
	if (++_cur > _max)
	{
	  throw std::overflow_error("Span full exception.");
	}
	_hasDup = !_set.insert(number).second;
}

void  Span::addNumber(int number, unsigned int n)
{
	if (_max - _cur < n)
	{
		throw std::overflow_error("Span full exception.");
	}
	_cur += n;
	while (n--)
	{
		_hasDup = !_set.insert(number).second;
	}
}

void  Span::addNumber(const std::vector<int>& vec)
{
	if (_max - _cur < vec.size())
	{
		throw std::overflow_error("Span full exception.");
	}
	_cur += vec.size();
	for (const int& x : vec)
	{
		_hasDup = !_set.insert(x).second;
	}
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    unsigned int size = std::distance(begin, end);
    if (_cur + size > _max)
    {
        throw std::overflow_error("Span full exception.");
    }
    _cur += size;
    for (auto it = begin; it != end; ++it)
    {
        _hasDup = !_set.insert(*it).second;
    }
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
{
    unsigned int size = std::distance(begin, end);
    if (_cur + size > _max)
    {
        throw std::overflow_error("Span full exception.");
    }
    _cur += size;
    for (auto it = begin; it != end; ++it)
    {
        _hasDup = !_set.insert(*it).second;
    }
}


size_t  Span::shortestSpan() const
{
	if (_cur == 0 || _cur == 1)
	{
		throw std::runtime_error("Shortestspan: not enough elements in set.");
	}
	if (_hasDup)
		return 0;
	std::set<int>::iterator  it;
	unsigned int             shortest_span = *_set.rbegin() - *_set.begin();
	unsigned int             curr_span;
	int                      prev_num = *_set.begin();

	for (it = ++_set.begin(); it != _set.end(); ++it)
	{
		curr_span = *it - prev_num;
		if (curr_span < shortest_span) {
		shortest_span = curr_span;
		}
		prev_num = *it;
	}
	return shortest_span;
}
  
size_t  Span::longestSpan() const 
{
	if (_cur == 0 || _cur == 1)
	{
		throw std::runtime_error("Longestspan: not enough elements in set.");
	}
	return *_set.rbegin() - *_set.begin();
}