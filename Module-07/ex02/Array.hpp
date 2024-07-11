#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <cstdlib>

template <class T> class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](int i) const;
	int  size() const;

	class except : public std::exception  {char const *what() const throw();};

private:
	T   *_array;
	int _size;
};

#include "Array.tpp"

#endif