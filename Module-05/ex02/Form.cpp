#include "Form.hpp"

Form::Form()
	:
	_name("Unkown contract"),
	_is_signed(false),
	_signed_grade(20),
	_executed_grade(8)
{
	std::cout << "Default constructor for Form\n";
}

Form::~Form() {
	std::cout << "Destructor for Form " << this->_name << "\n";
}

Form::Form(const Form &other)
	:
	_name(other._name),
	_is_signed(other._is_signed),
	_signed_grade(other._signed_grade),
	_executed_grade(other._executed_grade)
{
    std::cout << "Copy constructor called\n";
    if (this->_signed_grade > MIN || this->_executed_grade > MIN)
        throw GradeTooLowException();
    if (this->_signed_grade < MAX || this->_executed_grade < MAX)
        throw GradeTooHighException();
    if (this != &other)
        *this = other;
}

Form   &Form::operator=(const Form &other)  {
    std::cout << "Copy assignment operator called for " << this->_name << "\n";
    if (this == &other)
        return (*this);
    if (this->_signed_grade > MIN || this->_executed_grade > MIN)
        throw GradeTooLowException();
    if (this->_signed_grade < MAX || this->_executed_grade < MAX)
        throw GradeTooHighException();
    this->setName(other._name);
    this->_is_signed = other._is_signed;
    this->setSignedGrade(other._signed_grade);
    this->setExecutedGrade(other._executed_grade);
    return (*this);
}

Form::Form(string const str, int signed_grade, int executed_grade): 
			_name(str), 
			_signed_grade(signed_grade), 
			_executed_grade(executed_grade)  {
    std::cout << "Constructor for Form " << str << "\n";
    this->_is_signed = false;
    if (signed_grade > MIN || executed_grade > MIN)
        throw GradeTooLowException();
    if (signed_grade < MAX || executed_grade < MAX)
        throw GradeTooHighException();    
}

string const 	  Form::getName()   const {return (this->_name);}
bool              Form::isSigned()  const {return (this->_is_signed);}
int               Form::getSignedGrade() const {return (this->_signed_grade);}
int               Form::getExecutedGrade() const {return (this->_executed_grade);}

void	Form::setName(string const name) {
	string *tmp = (string *)&_name;
	*tmp = name;
}
void	Form::setSignedGrade(unsigned int n) {
	unsigned int *tmp = (unsigned int *)&_signed_grade;
	*tmp = n;
}
void	Form::setExecutedGrade(unsigned int n) {
	unsigned int *tmp = (unsigned int *)&_executed_grade;
	*tmp = n;
}

char        const *Form::GradeTooHighException::what() const throw(){return ("Form grade is too high");}
char        const *Form::GradeTooLowException::what()  const throw(){return ("Form grade is too low");}
char        const *Form::SignedException::what()       const throw(){return ("Form is already signed");}

void    Form::beSigned(const Bureaucrat &target)  {
    if (this->_is_signed)
        throw SignedException();
    if (target.getGrade() <= this->_signed_grade)
        this->_is_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &f)  {
    const int wh = 15;

    out << "Form " << f.getName() << " Bureaucrat ";
    if (f.isSigned())
        out << "✅ | ";
    else
        out << "❌ | ";
    out << std::setw(wh) << std::right << "Signed grade: " << std::setw(3) << f.getSignedGrade() << " | ";
    out << std::setw(wh) << std::right << "Executed grade: " << std::setw(3) << f.getExecutedGrade() << " |\n";
    return (out);
}