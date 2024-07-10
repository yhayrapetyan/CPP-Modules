#include "AForm.hpp"

AForm::AForm()
	:
	_name("Unkown contract"),
	_is_signed(false),
	_signed_grade(20),
	_executed_grade(8)
{
	std::cout << "Default constructor for AForm\n";
}

AForm::~AForm() {
	std::cout << "Destructor for AForm " << this->_name << "\n";
}

AForm::AForm(const AForm &other)
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

AForm   &AForm::operator=(const AForm &other)  {
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

AForm::AForm(string const str, int signed_grade, int executed_grade): 
			_name(str), 
			_signed_grade(signed_grade), 
			_executed_grade(executed_grade)  {
    std::cout << "Constructor for AForm " << str << "\n";
    this->_is_signed = false;
    if (signed_grade > MIN || executed_grade > MIN)
        throw GradeTooLowException();
    if (signed_grade < MAX || executed_grade < MAX)
        throw GradeTooHighException();    
}

string const 	  AForm::getName()   const {return (this->_name);}
bool              AForm::isSigned()  const {return (this->_is_signed);}
unsigned int      AForm::getSignedGrade() const {return (this->_signed_grade);}
unsigned int      AForm::getExecutedGrade() const {return (this->_executed_grade);}

void	AForm::setName(string const name) {
	string *tmp = (string *)&_name;
	*tmp = name;
}
void	AForm::setSignedGrade(unsigned int n) {
	unsigned int *tmp = (unsigned int *)&_signed_grade;
	*tmp = n;
}
void	AForm::setExecutedGrade(unsigned int n) {
	unsigned int *tmp = (unsigned int *)&_executed_grade;
	*tmp = n;
}

char        const *AForm::GradeTooHighException::what() const throw(){return ("AForm grade is too high");}
char        const *AForm::GradeTooLowException::what()  const throw(){return ("AForm grade is too low");}
char        const *AForm::SignedException::what()       const throw(){return ("AForm is already signed");}
char        const *AForm::ExecuteException::what()       const throw(){return ("AForm is not high enough for execute");}

void    AForm::beSigned(const Bureaucrat &target)  {
    if (this->_is_signed)
        throw SignedException();
    if (target.getGrade() <= this->_signed_grade)
        this->_is_signed = true;
    else
        throw GradeTooLowException();
}

void    AForm::execute(Bureaucrat const &executor) const   {
    if (this->_is_signed && executor.getGrade() <= this->_executed_grade)
        throw ExecuteException();
}

std::ostream &operator<<(std::ostream &out, AForm const &f)  {
    const int wh = 15;

    out << "AForm " << f.getName() << " Bureaucrat ";
    if (f.isSigned())
        out << "✅ | ";
    else
        out << "❌ | ";
    out << std::setw(wh) << std::right << "Signed grade: " << std::setw(3) << f.getSignedGrade() << " | ";
    out << std::setw(wh) << std::right << "Executed grade: " << std::setw(3) << f.getExecutedGrade() << " |\n";
    return (out);
}