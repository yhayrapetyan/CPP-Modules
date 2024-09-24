#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm ("Default constructor for SCForm", SCF_sign, SCF_exec){}
ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "Destructor for SCForm\n";}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {
    std::cout << "Copy constructor called in SCForm\n";
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)  {
    std::cout << "Copy assignment operator in SCForm called for " << other.getName() << "\n";
    if (this == &other)
        return (*this);
	AForm::operator=(other);
	this->_target = other._target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(string const target):
	AForm("SCForm", SCF_sign, SCF_exec),
	_target(target){
    std::cout << "Constructor for SCForm " << target << "\n"; 
}

string const ShrubberyCreationForm::getName()   const {return (this->_target);}

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
