#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main(void)
{
		/* Create the 3 forms and some Bureaucrats */

	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("Morty");
	PresidentialPardonForm pardon("Rick Sanchez");
	Bureaucrat mike("Mike", 150);
	Bureaucrat jon("Jon", 120);
	Bureaucrat steve("Steve", 3);
	
	/* Try to execute forms without being signed */
	{
		try
		{
			std::cout << mike << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			mike.executeForm(shrubbery);
			mike.executeForm(robotomy);
			mike.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign form and try to execute without enough grade */
	{
		try
		{
			std::cout << mike << std::endl;
			std::cout << jon << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			shrubbery.beSigned(jon);
			mike.executeForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign forms and execute them */
	{
		try
		{
			robotomy.beSigned(steve);
			pardon.beSigned(steve);
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			
			std::cout << "\n --------------------- \n\n";
			steve.executeForm(shrubbery);
			std::cout << "\n --------------------- \n\n";
			steve.executeForm(robotomy);
			std::cout << "\n --------------------- \n\n";
			steve.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";

	// {
	// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	// 	Bureaucrat *a = new Bureaucrat();
	// 	AForm *b = new PresidentialPardonForm("default");
	// 	// AForm *b = new RobotomyRequestForm();
	// 	// AForm *b = new ShrubberyCreationForm();
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
	// 	std::cout << *a;
	// 	std::cout << *b;

	// 	try
	// 	{
	// 		b->beSigned(*a);
	// 		// b->execute(*a);
	// 	} catch (AForm::GradeTooLowException &e) {
	// 		std::cerr << "\033[33m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
	// 	}

	// 	std::cout << *b;
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	// 	delete a;
	// 	delete b;
	// 	std::cout << std::endl;
	// }
	// std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	// {
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	// 	Bureaucrat *a = new Bureaucrat("Assistant", 145);
	// 	Bureaucrat *b = new Bureaucrat("CEO", 1);
	// 	AForm *c = new PresidentialPardonForm("some dude");
	// 	// Form *d = new Form(*c);
	// 	// Form *d = new Form("Rent Contract", 140, 100); // you are not able to construct an abstract class here
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
	// 	std::cout << *a;
	// 	std::cout << *b;
	// 	std::cout << *c;
	// 	std::cout << std::endl;

	// 	// Try to execute before signing
	// 	try
	// 	{
	// 		c->execute(*b);
	// 	}
	// 	catch (AForm::SignedException &e)
	// 	{
	// 		std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// 	// Assistant signs the Form
	// 	try
	// 	{
	// 		c->beSigned(*a);
	// 		// a->signForm(*c);
	// 	}
	// 	catch(Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
	// 	}

	// 	// CEO signs the Form
	// 	std::cout << std::endl;
	// 	std::cout << c;
	// 	std::cout << std::endl;
	// 	try
	// 	{
	// 		c->beSigned(*b);
	// 		// b->signForm(*c);
	// 	}
	// 	// catch(Form::GradeTooLowException &e)
	// 	catch(Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << c;
	// 	std::cout << std::endl;

	// 	// try signing the from again
	// 	std::cout << std::endl;
	// 	b->signForm(*c);
	// 	std::cout << std::endl;

	// 	// execute the Form from assistant
	// 	try
	// 	{
	// 		c->execute(*a);
	// 		// a.executeForm(*c);
	// 	}
	// 	catch(Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
	// 	}
	// 	std::cout << std::endl;

	// 	// execute Form from CEO
	// 	try
	// 	{
	// 		c->execute(*b);
	// 		// b.executeForm(*c);
	// 	}
	// 	catch(Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cerr << "\033[33m" << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	// 	delete a;
	// 	delete b;
	// 	delete c;
	// 	std::cout << std::endl;
	// }
	// std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	// {
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	// 	Bureaucrat *a = new Bureaucrat("Emperor", 1);
	// 	PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
	// 	PresidentialPardonForm *c = new PresidentialPardonForm(*b);
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
	// 	std::cout << a;
	// 	std::cout << b;
	// 	std::cout << c;
	// 	b->beSigned(*a);
	// 	a->signForm(*c);
	// 	b->execute(*a);
	// 	a->executeForm(*c);
	// 	// c->execute(*a);
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	// 	delete a;
	// 	delete b;
	// 	delete c;
	// 	std::cout << std::endl;
	// }
	// std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	// {
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	// 	Bureaucrat *a = new Bureaucrat("Emperor", 1);
	// 	RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
	// 	ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
	// 	std::cout << a;
	// 	std::cout << b;
	// 	std::cout << c;
	// 	b->beSigned(*a);
	// 	a->signForm(*c);
	// 	for (int i= 0; i < 10; i++)
	// 		b->execute(*a);
	// 	// a->executeForm(*c);
	// 	c->execute(*a);
	// 	std::cout << std::endl;

	// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	// 	delete a;
	// 	delete b;
	// 	delete c;
	// 	std::cout << std::endl;
	// }
	system("leaks bureaucrat");
	return (0);
}