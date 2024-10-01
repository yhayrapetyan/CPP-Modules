#include "RPN.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
        std::cout << "Error: invalid number of arguments\n";
        return (1);
    }
    std::string str = av[1];
    int result = Calculator::calculate(str);
    std::cout << result << "\n";
    return (0);
}