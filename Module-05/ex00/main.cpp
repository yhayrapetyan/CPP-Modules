#include "Bureaucrat.hpp"

int main()
{
	try {
		// Bureaucrat obj;
		// Bureaucrat obj21("Bob1", 10);
		// Bureaucrat obj22("Bob2", 1);
		// Bureaucrat obj23("Bob3", 150);
		Bureaucrat obj3("Jon", 0);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exceptoin" << e.what() << "\n";
	} catch (const Bureaucrat::GradeTooLowException & e){
		std::cout << "Exceptoin" << e.what() << "\n";
	}
	std::cout << "\n";
	try {
		Bureaucrat obj4("Harry", 151);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exceptoin" << e.what() << "\n";
	} catch (const Bureaucrat::GradeTooLowException & e){
		std::cout << "Exceptoin" << e.what() << "\n";
	}
	std::cout << "\n";
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
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exceptoin" << e.what() << "\n";
	} catch (const Bureaucrat::GradeTooLowException & e){
		std::cout << "Exceptoin" << e.what() << "\n";
	}
	return (0);
}