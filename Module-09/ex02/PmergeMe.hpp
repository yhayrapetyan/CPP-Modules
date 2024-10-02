#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <stack>
#include <cmath>

class PmergeMe
{

public:
	static void print(int ac, char **av);

private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

};

template <typename Container>
Container merge(const Container& left, const Container& right) {
    Container result;
    typename Container::const_iterator l_it = left.begin();
    typename Container::const_iterator r_it = right.begin();

    while (l_it != left.end() && r_it != right.end()) {
        if (*l_it <= *r_it) {
            result.push_back(*l_it);
            ++l_it;
        } else {
            result.push_back(*r_it);
            ++r_it;
        }
    }

    result.insert(result.end(), l_it, left.end());
    result.insert(result.end(), r_it, right.end());

    return result;
}

template <typename Container>
void	inserion_sort(Container &c)
{
	for (size_t i = 1; i < c.size(); i++)
	{
		int	j = i;
		while (j > 0 && c[j - 1] > c[j])
		{
			std::swap(c[j - 1], c[j]);
			j--;
		}
	}
}

template <typename Container>
void	insert(Container &left, Container &right)
{
	size_t n = 0;
	size_t power = 0;
	size_t start = 0;
	size_t end = 0;

	for (size_t i = 0; i < right.size();)
	{
		++power;

		n = pow(2, power) - n;

		start += n;

		end = start - n;

		if (start > right.size())
			start = right.size();

		for (size_t j = start - 1; j >= end;)
		{
			left.insert(std::upper_bound(left.begin(), left.end(), right[j]), right[j]);
			++i;
			if (j == 0)
				break ;
			--j;
		}
	}
}


template <typename Container>
void fordJohnsonSort(Container& cont)
{
	Container	left;
	Container	right;

	if (cont.size() < 4) {
		inserion_sort(cont);
		return;
	}
	for (size_t i = 0; i < cont.size() / 2; i++)
	{
		int	_a = cont[2 * i];
		int	_b = cont[2 * i + 1];
		if (_a > _b)
		{
			left.push_back(_b);
			right.push_back(_a);
		}
		else
		{
			left.push_back(_a);
			right.push_back(_b);
		}
	}
	if (cont.size() % 2 == 1)
		right.push_back(cont[cont.size() - 1]);
	fordJohnsonSort(left);
	insert(left, right);
	cont = left;
}

template<typename Container> 
void display(const Container &arr)
{
    typename Container::const_iterator it = arr.begin();
    if (it != arr.end()) {
        std::cout << *it;
        ++it;
    }
    while (it != arr.end()) {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << std::endl;
}

#endif