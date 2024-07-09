#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>

typedef std::string string;

#define MIN 1
#define MAX 150

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(string const name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	string const   		getName() const;
	unsigned int        getGrade() const;
	void                increment();
	void                decrement();

private:
	string const _name;
	unsigned int _grade;

	class GradeTooHighException : public std::exception {
        public:
			char const  *what() const throw();
	};

    class GradeTooLowException : public std::exception  {
        public:
			char const  *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &i);

#endif