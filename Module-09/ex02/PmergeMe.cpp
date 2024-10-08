#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){};
PmergeMe::PmergeMe(const PmergeMe &other){
	(void)other;
};
PmergeMe &PmergeMe::operator=(const PmergeMe &other){
	(void)other;
	return (*this);
};
PmergeMe::~PmergeMe(){};

static bool chekcOverflow(char  *line)
{
	long	nbr = std::atol(line);
	return (nbr > INT_MAX || nbr < INT_MIN);
}

static bool isValidInt(const std::string &str)   {
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

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
		if (!isValidInt(av[i])) {
			std::cout << "Error:: Invalid int " << av[i] << "\n";
			exit(1);
		}
		if (chekcOverflow(av[i])) {
			std::cout  << "Error: overflow " << av[i] << "\n";
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
	std::deque<int> deque_arr(vector_arr.begin(), vector_arr.end());
	std::cout << "Before: ";
	display(vector_arr);
	clock_t start_time = clock();
	fordJohnsonSort(vector_arr);
	clock_t end_time = clock();
	double  vector_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	start_time = clock();
	fordJohnsonSort(deque_arr);
	end_time = clock();
	display(deque_arr);
	double  deque_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process with vector container: " << std::fixed << std::setprecision(5) << vector_time << " seconds\n";
    std::cout << "Time to process with deque container:  " << std::fixed << std::setprecision(5) << deque_time << " seconds\n";

}
