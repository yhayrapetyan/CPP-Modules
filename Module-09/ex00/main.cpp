#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: invalid numbers of argument\n";
		return (1);
	}
	try {
		std::string filename = av[1];
		BitcoinExchange btc(filename);

		btc.exchange();
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return (0);
}