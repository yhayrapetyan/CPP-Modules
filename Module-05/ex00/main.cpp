#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	obj("Bob", 10);
		std::cout << obj;
		std::cout << "------------------\n";
		for (int i = 0; i < 5; i++)
			obj.decrement();
		std::cout << "------------------\n";
		std::cout << obj;
		std::cout << "------------------\n";
		for (int i = 0; i < 500; i++)
			obj.increment();
		std::cout << "------------------\n";
		std::cout << obj;
		std::cout << "------------------\n";
	}
	catch(const std::exception &exc) {
		std::cout << "EXCEPTION "  << exc.what() << std::endl;
	}
	return (0);
}