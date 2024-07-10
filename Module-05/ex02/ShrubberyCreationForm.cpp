#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm ("Default constructor for SCForm", SCF_sign, SCF_exec){}
ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "Destructor for SCForm\n";}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm() {
    std::cout << "Copy constructor called in SCForm\n";
    if (this != &other)
        *this = other;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)  {
    std::cout << "Copy assignment operator in SCForm called for " << other.getName() << "\n";
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

ShrubberyCreationForm::ShrubberyCreationForm(string const target) {
    std::cout << "Constructor for SCForm " << target << "\n"; 
    this->setName(target);
    this->setSignedGrade(SCF_sign);
    setExecutedGrade(SCF_exec);
    AForm::setName(target);//idk about this
}

string const ShrubberyCreationForm::getName()   const {return (this->_target);}

void              ShrubberyCreationForm::setName(string const name) {
	string *tmp = (string *)&_target;
	*tmp = name;
}

char        const *ShrubberyCreationForm::SCFException::what() const throw(){return ("Couldn't open the file");}


void        ShrubberyCreationForm::execute(Bureaucrat const &executor) const    {
    std::ofstream   outfile;
    string file = 	this->getName();

    if (executor.getGrade() > getExecutedGrade())
        throw AForm::GradeTooHighException();
    file.append("_shrubbery");
    outfile.open(file.c_str());
    if (!outfile.is_open())
        throw ShrubberyCreationForm::SCFException();
    outfile << TREE << "\n";
    outfile.close();
}
