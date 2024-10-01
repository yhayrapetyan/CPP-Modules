#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Error: invalid number of arguments\n";
		return (1);
	}
	
	PmergeMe::print(ac, av);
	return (0);
}