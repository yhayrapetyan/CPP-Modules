#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm ("Default constructor for RRForm", RRF_sign, RRF_exec){}
RobotomyRequestForm::~RobotomyRequestForm(){std::cout << "Destructor for RRForm\n";}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): 
		AForm(other), 
		_target(other._target) {
    std::cout <<  "Copy constructor called\n";
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)  {
    std::cout << "Copy assignment operator called for " << other.getName() << "\n";
    if (this == &other)
        return (*this);
	AForm::operator=(other);
	this->_target = other._target;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(string const target): 
	AForm("RRForm", RRF_sign, RRF_exec),
	_target(target)   {
    std::cout << "Constructor for RRForm " << target << "\n"; 
}

string const RobotomyRequestForm::getName()   const {return (this->_target);}

void        RobotomyRequestForm::execute(Bureaucrat const &executor) const      {
    if (executor.getGrade() > this->getExecutedGrade())
        throw AForm::GradeTooHighException();
    std::srand(std::time(NULL));
    if (std::rand() % 100 < 50)
        std::cout << this->getName() << " robotomized not successfully\n";
	else
        std::cout << this->getName() << " robotomized successfully\n";
}