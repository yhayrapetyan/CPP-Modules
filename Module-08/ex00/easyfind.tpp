#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>

typename T::iterator easyfind(T &container, int i) {
	return (std::find(container.begin(), container.end(), i));
}

#endif