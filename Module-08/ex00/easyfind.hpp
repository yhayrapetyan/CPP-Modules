#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>

typename T::iterator easyfind(T &container, int i);

#include "easyfind.tpp"

#endif