#ifndef SPAN_H
# define SPAN_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

class Span  {

public:
	typedef std::priority_queue<int, std::vector<int>, std::greater<int> > container_type;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	Span &operator=(const Span &other);
	~Span();
	
	void    addNumber(int n);
	int     shortestSpan() const;
	int     longestSpan() const;

	template <class T> void    addNumber(T start, T end);

private:
	// std::vector<int>    _vec;
	size_t _size;
	container_type    _span;
};

template <typename It> void	Span::addNumber(It start, It end)
{
    while (start != end) {
        addNumber(*start);
        ++start;
    }
}

#endif