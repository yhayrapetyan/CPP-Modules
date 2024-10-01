#include "RPN.hpp"
#include <cstddef>

Calculator::Calculator(){};
Calculator::~Calculator(){};
Calculator::Calculator(const Calculator &copy){(void)copy;}
Calculator	&Calculator::operator=(const Calculator &other) {
	if (this == &other)
		return *this;
	return (*this);
}

bool Calculator::isOperation(char token){
	return token == '+' || token == '-' || token == '*' || token == '/';
}

bool Calculator::isValidInput(std::string &str)    {
    for (size_t i = 0; i < str.size(); ++i) {
        char    c = str[i];
        if (std::isspace(c))
            continue;
        else if (std::isdigit(c))
            continue;
        else if (c == '+' || c == '-' || c == '*' || c == '/')
            continue;
        else {
            std::cout << "Error: Non-numeric input\n";
            std::cout <<  str.substr(0, i) << c << str.substr(i + 1) << "\n";
            return false ;
        }
    }
    return true ;
}

int Calculator::operation(int num1, int num2, char op)    {
    if (op == '+')
        return num1 + num2;
    else if (op == '-')
        return num1 - num2;
    else if (op == '*')
        return num1 * num2;
    else if (op == '/') {
        if (num2 == 0) {
            std::cout << "Error: you can't divide to 0\n";
            exit(1);
        }
        return num1 / num2;
    }
    std::cout << "Error: Wrong input\n";
    exit(1);
}

int Calculator::calculate(std::string &str)  { 
    std::stack<int>     stack;
	size_t					i;
	
	if (!isValidInput(str))
        exit(1); 

	i = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			continue;
		}

        if (isOperation(str[i])) {
            if (stack.size() < 2) {
                std::cout << "Error: Missing number before operation: " << str[i] << "\n";
                exit(1);
            }
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            int res = operation(num1, num2, str[i]);
            stack.push(res);
        } else {
            int number = static_cast<int>(str[i] - '0');
            stack.push(number);
        }
    }

    if (stack.size() != 1) {
        std::cout << "Error: Missing operator\n";
        exit(1);   
    }
    return stack.top();
}