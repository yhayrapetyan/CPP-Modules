#include "Span.hpp"

Span::Span()  : _size(0) {}
Span::~Span() {}

Span::Span(unsigned int N) : _size(N) {
}

Span::Span(const Span &copy) : _size(copy._size), _span(copy._span) {

}

Span	&Span::operator=(const Span &other) {
	if (this != &other) {
		this->_span = other._span;
		this->_size = other._size;
	}
	return (*this);
}

void    Span::addNumber(int n)	{
	if (this->_span.size() == this->_size)
		throw std::overflow_error("Error add number overflow");
	this->_span.push(n);
}


int     Span::shortestSpan() const	{

	if (_span.size() < 2)
		throw std::logic_error("Error span size less than 2");

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
		throw std::logic_error("Error span size less than 2");
	Span::container_type _copy = this->_span;
	while (_copy.size() > 1)
	{
		_copy.pop();
	}

	return _copy.top() - _span.top();
	
}
