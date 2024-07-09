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
        Form(string const name, int sg, int efg);
        Form(const Form &other);
        Form &operator=(const Form &other);
    
        string const   		getFName() const;
        bool                getFGrade() const;
        int                 getsgGrade() const;
        int                 getefgGrade() const;
        void                setFName(string const name);
        void                setsgGrade(int n);
        void                setefgGrade(int n);
        void                beSigned(const Bureaucrat &target);

        class GradeTooHighException : public std::exception {public: char const  *what() const throw();};
        class GradeTooLowException : public std::exception  {public: char const  *what() const throw();};
        class SignedException : public std::exception       {public: char const  *what() const throw();};

    private:
        string const  		 _fname;
        bool                _is_signed;
        int const           _signed_grade;
        int const           _executed_fgrade;
                    };

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif