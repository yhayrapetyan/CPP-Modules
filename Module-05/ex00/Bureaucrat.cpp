#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default Name") {
	this->_grade = MIN;
	std::cout <<  "Default constructor for Bureaucrat\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor for Bureaucrat "  << this->getName() << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()) {
    std::cout << "Copy constructor for Bureaucrat\n";
    if (other.getGrade() > MIN)
        throw GradeTooLowException();
    if (other.getGrade() < MAX)
        throw GradeTooHighException();
    if (this != &other)
        *this = other;
}

Bureaucrat   &Bureaucrat::operator=(const Bureaucrat &other)  {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    if (other.getGrade() > MIN)
        throw GradeTooLowException();
    if (other.getGrade() < MAX)
        throw GradeTooHighException();  
    this->_grade = other.getGrade();
    return (*this);
}

Bureaucrat::Bureaucrat(std::string const str, int grade): _name(str)  {
    std::cout << "Constructor for " << str << "\n";
    if (grade > MIN)
        throw GradeTooLowException();
    if (grade < MAX)
        throw GradeTooHighException();
    this->_grade = grade;
}

string const Bureaucrat::getName() const {return (this->_name);}
unsigned int Bureaucrat::getGrade() const {return (this->_grade);}

void    Bureaucrat::increment() {
    std::cout << "Increment\n";
    if (this->_grade == MAX)
        throw GradeTooHighException();
    this->_grade -= 1;
}

void    Bureaucrat::decrement() {
    std::cout << "Decrement\n";
    if (this->_grade == MIN)
        throw GradeTooLowException();
    this->_grade += 1;
}

char	const *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high!");
}

char	const *Bureaucrat::GradeTooLowException::what()  const throw(){
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bur)  {
    out << bur.getName() << "'s grade is " << bur.getGrade() << "\n";
    return (out);
}