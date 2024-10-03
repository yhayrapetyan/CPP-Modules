#include "ScalarConverter.hpp"
#include "Utils.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)   {
	if (this != &copy)
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)   {
    if (this == &other)
        return (*this);
    return (*this);
}

void ScalarConverter::convert(const string &str)   {
    if (Utils::isChar(str))
        ScalarConverter::convertChar(str);
    else if (Utils::isInt(str))
        ScalarConverter::convertInt(str);
    else if (Utils::isFloat(str))
        ScalarConverter::convertFloat(str);
    else if (Utils::isDouble(str))
        ScalarConverter::convertDouble(str);
    else
        std::cout << "Invalid input: " << "[" << str << "]\n";
}

void    ScalarConverter::convertChar(const string &str) {
    char    c = str[0];

    if (c >= 0 && c <= 127) {
        if (std::isprint(c) == 0)
                std::cout << "char:   Non displayable\n";
        else
            std::cout << "char:   " << c << "\n";
    }
    else
        std::cout << "char:   impossible\n";
    std::cout << "int:    " << static_cast<int>(c) << "\n";
    std::cout << "float:  " << static_cast<float>(c)  <<".0f\n";
    std::cout << "double: " << static_cast<double>(c) <<".0\n";
}

void ScalarConverter::convertInt(const string &str)  {
	
	if (Utils::chekcOverflow((string)str)) {
		std::cerr << "Int overflow of: " << str << "\n";
		return;
	}
	int n = Utils::strToInt(str);
    if (n < 0 || n > 127)
        std::cout << "char:   impossible\n";
    else if (n >= 32 && n < 127)
        std::cout << "char:   " << static_cast<char>(n) <<  "\n";  
    else
        std::cout << "char:   Non displayable\n";
    std::cout << "int:    " << static_cast<int>(n) << "\n";
    std::cout << "float:  " << static_cast<float>(n) <<".0f\n";
    std::cout << "double: " << static_cast<double>(n) <<".0\n";
}


void ScalarConverter::convertFloat(const string &str) {
	float number = Utils::strToFloat(str);
	std::ios oldState(NULL);
    oldState.copyfmt(std::cout);

    if (Utils::check_limits(str) || number < 0 || number > 127)
        std::cout << "char: impossible\n";
    else if (number >= 32 && number < 127)
        std::cout << "char: " << static_cast<char>(number) << "\n";
    else
        std::cout << "char: Non displayable\n";
    if (Utils::check_limits(str) || number > INT_MAX || number < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(number) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	if (Utils::check_limits(str)) {
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str << "\n";
	} else {
		std::cout << "float: "  << static_cast<float>(number)  << "f\n";
		std::cout << "double: " << static_cast<double>(number) << "\n";
	}
	std::cout.copyfmt(oldState);
}

void ScalarConverter::convertDouble(const string &str) {
    double number = std::stod(str);
	std::ios oldState(NULL);
    oldState.copyfmt(std::cout);

    if (Utils::check_limits(str) || number < 0 || number > 127)
        std::cout << "char: impossible\n";
    else if (number >= 32 && number < 127)
        std::cout << "char: " << static_cast<char>(number) <<  "\n";
    else
        std::cout << "char: Non Displayable\n";
    if (Utils::check_limits(str) || number > INT_MAX || number < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: "    << static_cast<int>(number) << "\n";
	std::cout << std::fixed << std::setprecision(1);
    if (Utils::check_limits(str)) {
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str << "\n";
	} else {
		std::cout << "float: "  << static_cast<float>(number)  << "f\n";
		std::cout << "double: " << static_cast<double>(number) << "\n";
	}
	std::cout.copyfmt(oldState);
}
