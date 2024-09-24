#include "Span.hpp"

Span::Span()  : _size(0) {}
Span::~Span() {}

Span::Span(unsigned int N) : _size(N) {
	// this->_span.reserve(N);
}

Span::Span(const Span &copy) : _size(copy._size), _span(copy._span) {
	// this->_span.reserve(copy._span.capacity());
	// this->_span = copy._span;
}

Span	&Span::operator=(const Span &other) {
	if (this != &other) {
		// this->_span.reserve(other._span.capacity());
		this->_span = other._span;
		this->_size = other._size;
	}
	return (*this);
}

void    Span::addNumber(int n)	{
	if (this->_span.size() == this->_size)
		throw std::overflow_error("Error add number stop working");
	this->_span.push(n);
}


int     Span::shortestSpan() const	{

	if (_span.size() < 2)
		throw std::logic_error("Error shortest span stop working");

	Span::container_type _copy = this->_span;
	int _elem = _copy.top();
	_copy.pop();
	int	_min = std::abs(_elem - _copy.top());
	while (!_copy.empty())
	{
		_elem = _copy.top();
		_copy.pop();
		if (!_copy.empty())
			_min = std::min(_min, std::abs(_elem - _copy.top()));
	}
	return _min;
}

int     Span::longestSpan() const	{
	if (this->_span.size() < 2)
		throw std::logic_error("Error longest span stop working");
	Span::container_type _copy = this->_span;
	while (_copy.size() > 1)
	{
		_copy.pop();
	}

	return _copy.top() - _span.top();
	
}

// void    Span::addNumber(int n)	{
// 	if (this->_span.size() == this->_span.capacity())
// 		throw std::overflow_error("✅Error add number stop working");
// 	this->_span.push_back(n);
// 	std::sort(_span.begin(), _span.end());
// }

// int     Span::shortestSpan() const	{
// 	int	min;

// 	if (_span.size() < 2)
// 		throw std::logic_error("Error shortest span stop working");
	
// 	std::vector<int> tmp = this->_span;
// 	std::sort(tmp.begin(), tmp.end());
// 	min = tmp[1] - tmp[0];
// 	for (size_t i = 2; i < tmp.size(); i++)
// 	{
// 		if (min > tmp[i] - tmp[i - 1])
// 			min = tmp[i] - tmp[i - 1];
// 	}
// 	return (min);
// }

// template <class T> void    addNumber(T start, T end)
// {
// 	for (; start != end; start++)
// 		this->addNumber(*end);
// }