#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

std::vector<int> fordJohnsonSort(std::vector<int> &arr);
std::vector<int> mergeInsertSort(std::deque<int> &arr);

template<typename Container> void display(const Container &arr)
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