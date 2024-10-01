#include "PmergeMe.hpp"

void PmergeMe::print(int ac, char **av)
{
	std::vector<int> vector_arr;

	for (int i = 1; i < ac; ++i) {
        int num = std::atoi(av[i]);
        if (num <= 0)
        {
            std::cout << "Error: invalid input\n";
            return ;   
        }
        vector_arr.push_back(num);
    }
	std::cout << "Vector\n";
	display(vector_arr);
	display(fordJohnsonSort(vector_arr));
	std::cout << "Deque\n";
	std::deque<int> deque_arr(vector_arr.begin(), vector_arr.end());
	display(deque_arr);
	// fordJohnsonSort(deque_arr);
	display(fordJohnsonSort(deque_arr));
	// std::cout << "STACK\n";
	// std::stack<int> myStack;

    // // Push elements onto the stack (1, 2, 3, 4)
    // myStack.push(1);
    // myStack.push(2);
    // myStack.push(3);
    // myStack.push(4);
	// fordJohnsonSort(myStack);
}

// //======VECTOR======
// std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
//     std::vector<int> result;
//     std::vector<int>::const_iterator l_it = left.begin();
//     std::vector<int>::const_iterator r_it = right.begin();

//     while (l_it != left.end() && r_it != right.end()) {
//         if (*l_it <= *r_it) {
//             result.push_back(*l_it);
//             ++l_it;
//         } else {
//             result.push_back(*r_it);
//             ++r_it;
//         }
//     }

//     result.insert(result.end(), l_it, left.end());
//     result.insert(result.end(), r_it, right.end());

//     return result;
// }

// std::vector<int> fordJohnsonSort(std::vector<int>& vec) {
//     if (vec.size() <= 1) {
//         return vec;
//     }

//     std::size_t mid = vec.size() / 2;
//     std::vector<int> left(vec.begin(), vec.begin() + mid);
//     std::vector<int> right(vec.begin() + mid, vec.end());

//     left = fordJohnsonSort(left);
//     right = fordJohnsonSort(right);

//     return merge(left, right);
// }

// //======DEQUE======
// std::deque<int> merge(const std::deque<int>& left, const std::deque<int>& right) {
//     std::deque<int> result;
//     std::deque<int>::const_iterator l_it = left.begin();
//     std::deque<int>::const_iterator r_it = right.begin();

//     while (l_it != left.end() && r_it != right.end()) {
//         if (*l_it <= *r_it) {
//             result.push_back(*l_it);
//             ++l_it;
//         } else {
//             result.push_back(*r_it);
//             ++r_it;
//         }
//     }

//     result.insert(result.end(), l_it, left.end());
//     result.insert(result.end(), r_it, right.end());

//     return result;
// }

// std::deque<int> fordJohnsonSort(std::deque<int>& deq) {
//     if (deq.size() <= 1) {
//         return deq;
//     }

//     std::size_t mid = deq.size() / 2;
//     std::deque<int> left(deq.begin(), deq.begin() + mid);
//     std::deque<int> right(deq.begin() + mid, deq.end());

//     left = fordJohnsonSort(left);
//     right = fordJohnsonSort(right);

//     return merge(left, right);
// }