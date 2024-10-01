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