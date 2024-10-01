#include "RPN.hpp"
#include <cctype>
#include <climits>
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

int Calculator::operation(long long int num1,long long  int num2, char op)    {
    long long int result;

	result = 0;
	switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: you can't divide by 0\n";
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            std::cout << "Error: Wrong input\n";
            exit(1);
    }

    if (result > INT_MAX || result < INT_MIN) {
        std::cout << "Error: overflow\n";
        exit(1);
    }
	return (result);
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
			if (std::isdigit(str[i + 1])) {
				std::cout << "Error: you can't pass numbers which are greater than 9\n";
				exit(1); 
			}
            stack.push(number);
        }
    }

    if (stack.size() != 1) {
        std::cout << "Error: Missing operator\n";
        exit(1);   
    }
    return stack.top();
}