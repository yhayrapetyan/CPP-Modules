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
	// static int  calcule(const std::string &str);

private:
	static bool isop(const std::string &token);
	static bool isValidInput(const std::string &str);
	// static int  operation(int num1, int num2, const std::string &op);
};

#endif