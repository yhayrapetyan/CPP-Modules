#include "Form.hpp"

Form::Form() :
				_signed_grade(20),
				_executed_fgrade(8) {
	this->_is_signed = false;
	std::cout << "Default constructor for Form\n";
}

Form::~Form() {
	std::cout << "Destructor for Form " << this->getFName() << "\n";
}

Form::Form(const Form &other) :
								_fname(other.getFName()),
								_signed_grade(other.getsgGrade()),
								_executed_fgrade(other.getefgGrade()) {
    std::cout << "Copy constructor called\n";
    if (this->_signed_grade > MIN || this->_executed_fgrade > MIN)
        throw GradeTooLowException();
    if (this->_signed_grade < MAX || this->_executed_fgrade < MAX)
        throw GradeTooHighException();
    if (this != &other)
        *this = other;
}

Form   &Form::operator=(const Form &other)  {
    std::cout << "Copy assignment operator called for " << this->getFName() << "\n";
    if (this == &other)
        return (*this);
    if (this->_signed_grade > MIN || this->_executed_fgrade > MIN)
        throw GradeTooLowException();
    if (this->_signed_grade < MAX || this->_executed_fgrade < MAX)
        throw GradeTooHighException();
    setFName(other.getFName());
    this->_is_signed = other.getFGrade();
    setsgGrade(other.getsgGrade());
    setefgGrade(other.getefgGrade());
    return (*this);
}

Form::Form(string const str, int sg, int efg): 
			_fname(str), 
			_signed_grade(sg), 
			_executed_fgrade(efg)  {
    std::cout << "Constructor for Form " << str << "\n";
    this->_is_signed = false;
    if (sg > MIN || efg > MIN)
        throw GradeTooLowException();
    if (sg < MAX || efg < MAX)
        throw GradeTooHighException();    
}

string const 	  Form::getFName()   const {return (this->_fname);}
bool              Form::getFGrade()  const {return (this->_is_signed);}
int               Form::getsgGrade() const {return (this->_signed_grade);}
int               Form::getefgGrade()const {return (this->_executed_fgrade);}

void              Form::setFName(string const name)    {string *tmp = (std::string *)&_fname; *tmp = name;}
void              Form::setsgGrade(int n)              {int *tmp = (int *)&_signed_grade;          *tmp = n;}
void              Form::setefgGrade(int n)             {int *tmp = (int *)&_executed_fgrade;       *tmp = n;}

char        const *Form::GradeTooHighException::what() const throw(){return ("Form grade is too high");}
char        const *Form::GradeTooLowException::what()  const throw(){return ("Form grade is too low");}
char        const *Form::SignedException::what()       const throw(){return ("Form is already signed");}

void    Form::beSigned(const Bureaucrat &target)  {
    if (this->_is_signed)
        throw SignedException();
    if (static_cast<int>(target.getGrade()) <= this->_signed_grade)
        this->_is_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &f)  {
    const int wh = 15;

    out << "Form " << f.getFName() << " Bureaucrat ";
    if (f.getFGrade())
        out << "✅ | ";
    else
        out << "❌ | ";
    out << std::setw(wh) << std::right << "Signed grade: " << std::setw(3) << f.getsgGrade() << " | ";
    out << std::setw(wh) << std::right << "Executed grade: " << std::setw(3) << f.getefgGrade() << " |\n";
    return (out);
}