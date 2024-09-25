#ifndef ITER_H
# define ITER_H

#include <iostream>

template <typename T> void iter (T *a, size_t l, void (*f)(T&)) {
	if (a == NULL || f == NULL)
		return;
    for (size_t i = 0; i < l; i++)
        f(a[i]);
}

template <typename T> void iter (const T *a, size_t l, void (*f)(const T&)) {
	if (a == NULL || f == NULL)
		return;
    for (size_t i = 0; i < l; i++)
        f(a[i]);
}

#endif