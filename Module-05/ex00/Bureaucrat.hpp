#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>

typedef std::string string;

#define MIN 150
#define MAX 1

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(string const name, unsigned int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	string const   		getName() const;
	unsigned int        getGrade() const;
	void                increment();
	void                decrement();
	
	class GradeTooHighException : public std::exception { public: char const  *what() const throw(); };
    class GradeTooLowException : public std::exception  { public: char const  *what() const throw(); };

private:
	string const _name;
	unsigned int _grade;

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &i);

#endif