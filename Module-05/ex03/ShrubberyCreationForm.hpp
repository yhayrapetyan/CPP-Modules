#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#define SCF_sign 145
#define SCF_exec 137

#include "AForm.hpp"
#include <fstream>

typedef std::string string;

class ShrubberyCreationForm : public AForm  {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(string const target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	std::string const   getName() const;
	void                setName(string const target);
	virtual void        execute(Bureaucrat const &executor) const;

	class SCFException : public std::exception {public: virtual char const  *what() const throw();};

private:
	string const _target;

};

#define TREE "                                                         .\n\
                                              .         ;  \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'     .,   \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'  \n\
                        `@%.  `;@%.      ;@@%;         \n\
                          `@%%. `@%%    ;@@%;        \n\
                            ;@%. :@%%  %@@%;       \n\
                              %@bd%%%bd%%:;     \n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '         \n\
                                %@@@o%;:(.,'         \n\
                            `.. %@@@o%::;         \n\
                               `)@@@o%::;         \n\
                                %@@(o)::;        \n\
                               .%@@@@%::;         \n\
                               ;%@@@@%::;.          \n\
                              ;%@@@@%%:;;;. \n\
                          ...;%@@@@@%%:;;;;,.."                                   
#endif