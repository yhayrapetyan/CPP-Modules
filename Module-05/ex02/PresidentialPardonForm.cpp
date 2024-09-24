#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm ("Default constructor for PPForm", PPF_sign, PPF_exec){}
PresidentialPardonForm::~PresidentialPardonForm(){std::cout << "Destructor for PPForm \n";}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
		AForm(other),
		_target(other._target) {
    std::cout << "Copy constructor called\n";
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)  {
    std::cout << "Copy assignment operator called for " << other.getName();
    if (this == &other)
        return (*this);
	AForm::operator=(other);	
	this->_target = other._target;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(string const target): 
	AForm("PPForm", PPF_sign, PPF_exec),
	_target(target) {
    std::cout <<  "Constructor for PPForm " << target << "\n"; 
}

string const PresidentialPardonForm::getName()   const {return (this->_target);}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const   {
    if (executor.getGrade() > getExecutedGrade())
        throw AForm::GradeTooHighException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}