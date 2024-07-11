#include "Span.hpp"

int main()
{
	// Span sp = Span(5);


	// sp.addNumber(3);
	// sp.addNumber(6);
	// sp.addNumber(9);
	// sp.addNumber(17);
	// sp.addNumber(11);
	// sp.addNumber(17);
	// sp.addNumber(11);
	// sp.addNumber(17);
	// sp.addNumber(11);
	// sp.addNumber(11);


	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	{
		std::cout << "BASIC\n";
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		try
		{
			sp.addNumber(0);
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		std::cout << "\033[1;32mInfo: \033[0;34mSpan::shortestSpan: \033[0m" << sp.shortestSpan() << std::endl;
		std::cout << "\033[1;32mInfo: \033[0;34mSpan::longestSpan: \033[0m" << sp.longestSpan() << std::endl;
		std::cout << "\n";
	}

	{
		int const myints[] = {6, 3, 9, 17,  11};
		Span sp = Span(5);

		sp.addNumber(myints, myints + 5);

		try
		{
			sp.addNumber(myints, myints + 3);
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		std::cout << "\033[1;32mInfo: \033[0;34mSpan::shortestSpan: \033[0m" << sp.shortestSpan() << std::endl;
		std::cout << "\033[1;32mInfo: \033[0;34mSpan::longestSpan: \033[0m" << sp.longestSpan() << std::endl;
		std::cout << "\n";
	}

	{
		std::cout << "EMPTY\n";
		Span sp = Span();
		std::vector<int> myvector(1);
		// std::vector<int> myvector(0);// this doesn't crush the program but it's doesn't show any message

		myvector.push_back(1);

		try
		{
			sp.shortestSpan();
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		try
		{
			sp.longestSpan();
		}
		catch (std::exception const &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
		}

		try
		{
			// std::cout << "DEBUG\n";
			sp.addNumber(myvector.front());
			// std::cout << "DEBUG2\n";
		}
		catch (std::exception const &e)
		{
			// std::cout << "fdsafdsa\n";
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << '\n';
			// std::cout << "SOMEFDIS";
		}
		std::cout << "\n";
	}

	return 0;
}