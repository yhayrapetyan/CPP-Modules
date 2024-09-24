#ifndef AFORM_H
# define AFORM_H

#include "Bureaucrat.hpp"
#include <iomanip>

typedef std::string string;

class	Bureaucrat;

class AForm  {
public:
	AForm();
	virtual ~AForm();
	AForm(string const name, int signed_grade, int executed_grade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	string const   		getName() const;
	bool                isSigned() const;
	unsigned int        getSignedGrade() const;
	unsigned int        getExecutedGrade() const;

	void                beSigned(const Bureaucrat &target);
	virtual void		execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {public: char const  *what() const throw();};
	class GradeTooLowException : public std::exception  {public: char const  *what() const throw();};
	class SignedException : public std::exception       {public: char const  *what() const throw();};
	class ExecuteException : public std::exception      {public: char const  *what() const throw();};

private:
	string const  		 _name;
	bool                _is_signed;
	unsigned int const  _signed_grade;
	unsigned int const  _executed_grade;

};

std::ostream &operator<<(std::ostream &out, AForm const &f);

#endif