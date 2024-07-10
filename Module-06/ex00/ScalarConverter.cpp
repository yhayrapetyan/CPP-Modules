#include "ScalarConverter.hpp"

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
    if (ScalarConverter::isChar(str))
        ScalarConverter::convertChar(str);
    else if (ScalarConverter::isInt(str))
        ScalarConverter::convertInt(str);
    else if (ScalarConverter::isFloat(str))
        ScalarConverter::convertFloat(str);
    else if (ScalarConverter::isDouble(str))
        ScalarConverter::convertDouble(str);
    else
        std::cout << "Invalid input: " << "[" << str << "]\n";
}

bool ScalarConverter::isChar(const std::string &str) {
	return str.length() == 1 && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const string &str)   {
    std::istringstream str_stream_obj(str);
    int n;
    str_stream_obj >> n;
    return !str_stream_obj.fail() && str_stream_obj.eof();
}

bool ScalarConverter::isFloat(const string &str) {
    const char* cstr = str.c_str();
    char* endptr;

    std::strtof(cstr, &endptr);
    if (endptr == cstr)
        return false;
    while (*endptr != '\0')
    {
        if (*endptr != 'f')
            return false;
        ++endptr;
    }
    return true;
}

bool ScalarConverter::isDouble(const string &str) {
    const char* cstr = str.c_str();
    char* endptr;

    std::strtod(cstr, &endptr);
    if (endptr == cstr)
        return false;
    while (*endptr != '\0')
    {
        if (*endptr != 'f')
            return false;
        ++endptr;
    }
    return true;
}

void    ScalarConverter::convertChar(const string &str) {
    char    c = str[0];

    if (c >= 0 && c <= 127) {
        if (isprint(c) == 0)
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
    int n = std::atoi(str.c_str());
    
    if (n < -128 || n > 127)//< 0
        std::cout << "char:   impossible\n";
    else if (n >= 32 && n < 127)
        std::cout << "char:   " << static_cast<char>(n) <<  "\n";  
    else
        std::cout << "char:   Non displayable\n";
    std::cout << "int:    " << static_cast<int>(n) << "\n";
    std::cout << "double: " << static_cast<double>(n) <<".0\n";
    std::cout << "float:  " << static_cast<float>(n) <<".0f\n";
}

bool ScalarConverter::check_limits(const string &str)
{
    if (str == "inf" || str == "+inf" || str == "-inf" || str == "inff" || str == "+inff" || str == "-inff" || str == "nan" || str == "nanf")
        return true;
    return false;
}

void ScalarConverter::convertFloat(const string &str) {
    double number = std::strtod(str.c_str(), NULL);

    if (ScalarConverter::check_limits(str) || number < -128 || number > 127)
        std::cout << "char: impossible\n";
    else if (number >= 32 && number < 127)
        std::cout << "char: " << static_cast<char>(number) << "\n";
    else
        std::cout << "char: Non displayable\n";
    if (ScalarConverter::check_limits(str) || number > INT_MAX || number < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(number) << "\n";
    std::cout << "float: "  << static_cast<float>(number)  << "f\n";
    std::cout << "double: " << static_cast<double>(number) << "\n";
}

void ScalarConverter::convertDouble(const std::string &str) {
    double number = std::strtod(str.c_str(), NULL);

    if (ScalarConverter::check_limits(str) || number < -128 || number > 127)
        std::cout << "char: impossible\n";
    else if (number >= 32 && number < 127)
        std::cout << "char: " << static_cast<char>(number) <<  std::endl;
    else
        std::cout << "char: Non Displayable" << std::endl;
    if (ScalarConverter::check_limits(str) || number > INT_MAX || number < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: "    << static_cast<int>(number) << "\n";
    std::cout << "float: "  << static_cast<float>(number)  <<"f"<< std::endl;
    std::cout << "double: " << number << std::endl;
}