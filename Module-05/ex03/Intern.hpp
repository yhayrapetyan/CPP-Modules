#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef std::string string;

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern &other);
	~Intern();

	AForm   *makeForm(string form_name, string target) const;

};
#endif