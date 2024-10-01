#include "PmergeMe.hpp"

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    std::vector<int>::const_iterator l_it = left.begin();
    std::vector<int>::const_iterator r_it = right.begin();

    // Merge the two sorted halves
    while (l_it != left.end() && r_it != right.end()) {
        if (*l_it <= *r_it) {
            result.push_back(*l_it);
            ++l_it;
        } else {
            result.push_back(*r_it);
            ++r_it;
        }
    }

    // Append the remaining elements
    result.insert(result.end(), l_it, left.end());
    result.insert(result.end(), r_it, right.end());

    return result;
}

std::vector<int> fordJohnsonSort(std::vector<int>& vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    // Divide the vector into two halves
    std::size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    // Recursively sort both halves
    left = fordJohnsonSort(left);
    right = fordJohnsonSort(right);

    // Merge the sorted halves
    return merge(left, right);
}