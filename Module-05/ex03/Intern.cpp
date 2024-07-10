#include "Intern.hpp"

Intern::Intern(){std::cout << "Default constructor for Intern\n";}
Intern::~Intern(){std::cout << "Destructor for Intern 💀\n";}

Intern::Intern(const Intern &other){
    std::cout <<  "Copy constructor called\n";
    if (this != &other)
        *this = other;
}

Intern   &Intern::operator=(const Intern &other)  {
    std::cout << "Copy assignment operator called for\n";
     if (this == &other)
        return (*this);
    return (*this);
}

AForm   *presidentForm(const string& target) {
	std::cout << "Intern creates PPF\n";
	 return new PresidentialPardonForm(target);
}

AForm   *robotForm(const string& target) {
	std::cout << "Intern creates RRF\n";
	return new RobotomyRequestForm(target);
}

AForm   *shruberryForm(const string& target) {
	std::cout << "Intern creates SCF\n"; 
	return new ShrubberyCreationForm(target);
}

AForm   *Intern::makeForm(string form_name, string target) const {
    const string fname[] = { //need to change fnames
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm"
    };
    AForm* (*form[])(const string&) = {&presidentForm, &robotForm, &shruberryForm};
    size_t num = sizeof(fname) / sizeof(fname[0]);

    for (size_t i = 0; i < num; ++i) {
        if (form_name == fname[i]) {
			return form[i](target);
            // TakeForm creator = form[i];
            // return creator(target);
        }
    }
    std::cout << "Intern didn't do the : " << form_name << "\n";
    return (0);
}