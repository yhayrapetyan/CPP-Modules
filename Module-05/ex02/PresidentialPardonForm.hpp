#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#define PPF_sign 25
#define PPF_exec 5

#include "AForm.hpp"

typedef std::string string;

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(string const target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	std::string const   getName() const;
	void                setName(string const target);
	virtual void        execute(Bureaucrat const &executor) const;

private:
	string const _target;

};
#endif