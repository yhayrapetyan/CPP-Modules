#include "PmergeMe.hpp"
#include <vector>

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Error: invalid number of arguments\n";
		return (1);
	}

	std::vector<int> array;

	for (int i = 1; i < ac; ++i) {
        int num = std::atoi(av[i]);
        if (num <= 0)
        {
            std::cout << "Error: invalid input\n";
            return (1);   
        }
        array.push_back(num);
    }
	display(array);
	display(fordJohnsonSort(array));

	return (0);
}