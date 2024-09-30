#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: invalid numbers of argument\n";
		return (1);
	}
	std::string filename = av[1];
    BitcoinExchange btc(filename);

	btc.exchange();

	return (0);
}