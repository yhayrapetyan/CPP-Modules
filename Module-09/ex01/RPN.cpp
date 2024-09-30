#include "RPN.hpp"

Calculator::Calculator(){};
Calculator::~Calculator(){};
Calculator::Calculator(const Calculator &copy){(void)copy;}
Calculator	&Calculator::operator=(const Calculator &other) {
	if (this == &other)
		return *this;
	return (*this);
}

bool Calculator::isop(const std::string& token){
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool Calculator::isValidInput(const std::string &str)    {
    for (size_t i = 0; i < str.size(); ++i)
    {
        char    c = str[i];
        if (std::isspace(c))
            continue;
        else if (std::isdigit(c))
            continue;
        else if (c == '+' || c == '-' || c == '*' || c == '/')
            continue;
        else
        {
            std::cerr << "Error: Non-numeric input\n";
            std::cout <<  str.substr(0, i) << c << str.substr(i + 1) << "\n";
            return false ;
        }
    }
    return true ;
}