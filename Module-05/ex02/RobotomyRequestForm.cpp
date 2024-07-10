#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm ("Default constructor for RRForm", RRF_sign, RRF_exec){}
RobotomyRequestForm::~RobotomyRequestForm(){std::cout << "Destructor for RRForm\n";}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm() {
    std::cout <<  "Copy constructor called\n";
    if (this != &other)
        *this = other;
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)  {
    std::cout << "Copy assignment operator called for " << other.getName() << "\n";
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

RobotomyRequestForm::RobotomyRequestForm(string const target)    {
    std::cout << "Constructor for RRForm " << target << "\n"; 
    this->setName(target);
    this->setSignedGrade(RRF_sign);
    this->setExecutedGrade(RRF_exec);
    AForm::setName(target);//idk
}

string const RobotomyRequestForm::getName()   const {return (this->_target);}
void              RobotomyRequestForm::setName(string const name) {
	string *tmp = (string *)&_target; 
	*tmp = name;
}

void        RobotomyRequestForm::execute(Bureaucrat const &executor) const      {
    if (executor.getGrade() > this->getExecutedGrade())
        throw AForm::GradeTooHighException();
    // system("say Oh, no! Oh my GOD!");
    std::srand(std::time(NULL));
    if (std::rand() % 100 < 50)
        std::cout << this->getName() << " robotomized not successfully\n";
	else
        std::cout << this->getName() << " robotomized successfully\n";
}