#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <stack>

// std::vector<int> fordJohnsonSort(std::vector<int> &arr);
// std::deque<int> fordJohnsonSort(std::deque<int> &arr);

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

// The Ford-Johnson sorting algorithm (merge-insertion sort) with templates
template <typename Container>
Container fordJohnsonSort(Container& cont) {
    if (cont.size() <= 1) {
        return cont;
    }

    typename Container::iterator mid = cont.begin();
    std::advance(mid, cont.size() / 2);

    Container left(cont.begin(), mid);
    Container right(mid, cont.end());

    left = fordJohnsonSort(left);
    right = fordJohnsonSort(right);

    return merge(left, right);
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