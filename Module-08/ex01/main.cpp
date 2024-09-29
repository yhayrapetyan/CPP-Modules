#include "Span.hpp"

int main()
{
	std::cout << "-------------------|Subject main test|--------------------\n";
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-------------------|Adding numbers More than N|--------------------\n";
	try
	{
		Span sp = Span(3);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-------------------|Adding Numbers using Template function|--------------------\n";
	try
	{
		std::vector<int> random;
		Span sp = Span(10000);
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			const int value = rand();
			random.push_back(value);
		}
		sp.addNumber(random.begin(), random.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-------------------|Adding Continer Bigger than N|--------------------\n";
	try
	{
		std::vector<int> random;
		Span sp = Span(7);
		srand(time(NULL));
		for (int i = 0; i < 77; i++)
		{
			const int value = rand();
			random.push_back(value);
		}
		sp.addNumber(random.begin(), random.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-------------------|Calling longestSpan with emoty Container|--------------------\n";
	try
	{
		Span sp = Span(7);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-------------------|Calling shortestSpan with emoty Container|--------------------\n";
	try
	{
		Span sp = Span(7);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-------------------|Calling longestSpan with one Number|--------------------\n";
	try
	{
		Span sp = Span(7);
		sp.addNumber(77);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-------------------|Calling shortestSpan with one Number|--------------------\n\n";
	try
	{
		Span sp = Span(7);
		sp.addNumber(77);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


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
