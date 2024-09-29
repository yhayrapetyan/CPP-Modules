#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>

typename T::iterator easyfind(T &container, int i) {
	typename T::iterator item = std::find(container.begin(), container.end(), i);

	if (item == container.end())
		throw std::out_of_range("Can't find Occurrence: " + std::to_string(i));
	return (item);
}

#endif