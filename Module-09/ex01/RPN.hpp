#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class Calculator   {
public:
	Calculator();
	Calculator(const Calculator &copy);
	Calculator &operator=(const Calculator &other);
	~Calculator();
	static int  calculate(std::string &str);

private:
	static bool isOperation(char token);
	static bool isValidInput(std::string &str);
	static int  operation(long long int num1,long long  int num2, char op);
};

#endif