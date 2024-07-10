#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>

typedef std::string string;

class ScalarConverter  {
public:

	static void convert(const std::string &str);

private:
	
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static bool isInt(const string& str);
	static bool isChar(const string& str);
	static bool isFloat(const string& str);
	static bool isDouble(const string& str);
	
	static void convertChar(const string& str);
	static void convertInt(const string& str);
	static void convertFloat(const string& str);
	static void convertDouble(const string& str);

	static bool check_limits(const string &str)

};

#endif