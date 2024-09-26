#ifndef ARRAY_T
# define ARRAY_T

#include "Array.hpp"


template <typename T>   Array<T>::Array() : _array(NULL), _size(0) {
	std::cout << "Array default constructor called\n";
}

template <typename T>   Array<T>::~Array(){
	std::cout << "Destructor called \n"; 
	delete [] _array;
}

template <typename T>   Array<T>::Array(const Array &copy) : _size(copy.size()) {
    std::cout << "Copy constructor called\n";
    _array = new T[_size]();
    for (int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
}

template <typename T>   Array<T> &Array<T>::operator=(const Array<T> &other)    {
    std::cout << "Copy assignment operator called\n";
    delete [] _array;
    _size = other.size();
    _array = new T[_size]();
    for (int i = 0; i < _size; i++)
        _array[i] = other._array[i];
    return (*this);
}

template <typename T>   Array<T>::Array(unsigned int n) : _size(n) {
	_array = new T[_size]();
}

template <typename T>   T &Array<T>::operator[](size_t i) const  {
    if (i < 0 || i > size() - 1)
        throw Array<T>::except();
    return _array[i];
}

template <typename T>  const T &Array<T>::operator[](size_t i) const  {
    if (i < 0 || i > size() - 1)
        throw Array<T>::except();
    return _array[i];
}

template <typename T>   int  Array<T>::size() const {return _size;}
template <typename T>   char const* Array<T>::except::what() const throw()  {return ("Out of range");}


#endif