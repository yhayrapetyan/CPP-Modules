#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>
#include <string>

typedef std::string string;

class ScalarConverter  {
public:

	static void convert(const std::string &str);

private:
	
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void convertChar(const string& str);
	static void convertInt(const string& str);
	static void convertFloat(const string& str);
	static void convertDouble(const string& str);

};

#endif