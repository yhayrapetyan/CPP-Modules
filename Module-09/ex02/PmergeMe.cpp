#include "PmergeMe.hpp"
#include <deque>

void PmergeMe::print(int ac, char **av)
{
	std::vector<int> 	vector_arr;
	std::string			line;

	for (int i = 1; i < ac; ++i) {
		line = av[i];
		if (line.find(" ") != std::string::npos) {
			std::cout << "Error: input shouldn't contain spaces\n";
			exit(1);
		}
        int num = std::atoi(av[i]);
        if (num <= 0)
        {
            std::cout << "Error: invalid input\n";
            return ;   
        }
        vector_arr.push_back(num);
    }
	std::cout << "Before: ";
	display(vector_arr);
	clock_t start_time = clock();
	std::vector<int> sorted_vector = fordJohnsonSort(vector_arr);
	clock_t end_time = clock();
	double  vector_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	std::deque<int> deque_arr(vector_arr.begin(), vector_arr.end());
	start_time = clock();
	std::deque<int> sorted_deque = fordJohnsonSort(deque_arr);
	end_time = clock();
	display(sorted_deque);
	double  deque_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process with vector container: " << std::fixed << std::setprecision(5) << vector_time << " seconds\n";
    std::cout << "Time to process with deque container:  " << std::fixed << std::setprecision(5) << deque_time << " seconds\n";

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