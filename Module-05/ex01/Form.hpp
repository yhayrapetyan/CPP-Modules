#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"
#include <iomanip>

typedef std::string string;

class	Bureaucrat;

class Form  {
public:
	Form();
	~Form();
	Form(string const name, int signed_grade, int executed_grade);
	Form(const Form &other);
	Form &operator=(const Form &other);

	string const   		getName() const;
	bool                isSigned() const;
	int                 getSignedGrade() const;
	int                 getExecutedGrade() const;

	void                beSigned(const Bureaucrat &target);

	class GradeTooHighException : public std::exception {public: char const  *what() const throw();};
	class GradeTooLowException : public std::exception  {public: char const  *what() const throw();};
	class SignedException : public std::exception       {public: char const  *what() const throw();};

private:
	string const  		 _name;
	bool                _is_signed;
	unsigned int const  _signed_grade;
	unsigned int const  _executed_grade;

};

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif