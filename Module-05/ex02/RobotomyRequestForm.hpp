#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#define RRF_sign 72
#define RRF_exec 45

#include "AForm.hpp"

typedef std::string string;

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(string const target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	string const   		getName() const;
	virtual void        execute(Bureaucrat const &executor) const;

private:
	string _target;
};
#endif