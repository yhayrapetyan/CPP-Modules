#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm ("Default constructor for PPForm", PPF_sign, PPF_exec){}
PresidentialPardonForm::~PresidentialPardonForm(){std::cout << "Destructor for PPForm \n";}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm() {
    std::cout << "Copy constructor called\n";
    if (this != &other)
        *this = other;
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)  {
    std::cout << "Copy assignment operator called for " << other.getName();
    if (this == &other)
        return (*this);
    if (other.getSignedGrade() > MIN || other.getExecutedGrade() > MIN)
        throw AForm::GradeTooLowException();
    if (other.getSignedGrade() < MAX || other.getExecutedGrade() < MAX)
        throw AForm::GradeTooHighException();
    this->setName(other.getName());
    this->setSignedGrade(other.getSignedGrade());
    this->setExecutedGrade(other.getExecutedGrade());
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(string const target) {
    std::cout <<  "Constructor for PPForm " << target << "\n"; 
    this->setName(target);
    this->setSignedGrade(PPF_sign);
    this->setExecutedGrade(PPF_exec);
    AForm::setName(target);//idk
}

string const PresidentialPardonForm::getName()   const {return (this->_target);}

void	PresidentialPardonForm::setName(std::string const name) {
	string *tmp = (string *)&_target;
	*tmp = name;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const   {
    if (executor.getGrade() > getExecutedGrade())
        throw AForm::GradeTooHighException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}