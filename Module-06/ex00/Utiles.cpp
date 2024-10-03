#include "Utils.hpp"

Utils::Utils(){}
Utils::~Utils(){}

Utils::Utils(const Utils &copy)   {
	if (this != &copy)
	*this = copy;
}

Utils &Utils::operator=(const Utils &other)   {
    if (this == &other)
        return (*this);
    return (*this);
}

bool Utils::check_limits(const string &str)
{
    if (str == "inf" || str == "+inf" || str == "-inf" || str == "inff" || str == "+inff" || str == "-inff" || str == "nan" || str == "nanf")
        return true;
    return false;
}

bool Utils::chekcOverflow(string str)
{
	if (std::strlen(str.c_str()) > 11)
		return (true);
	long	nbr = std::atol(str.c_str());
	return (nbr > INT_MAX || nbr < INT_MIN);
}

bool Utils::isChar(const std::string &str) {
	return str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]);
}

bool Utils::isInt(const string &str)   {
    std::istringstream str_stream_obj(str);
    int n;
    str_stream_obj >> n;
    return !str_stream_obj.fail() && str_stream_obj.eof();
}

bool Utils::isFloat(const string &str) {
    const char* cstr = str.c_str();
    char* endptr;

    std::strtof(cstr, &endptr);
    if (endptr == cstr)
        return false;
	if (endptr[0] == 'f' && endptr[1] == 'f')
		return false;
	while (*endptr != '\0')
    {
        if (*endptr != 'f')
            return false;
        ++endptr;
	}
    return true;
}

bool Utils::isDouble(const string &str) {
    const char* cstr = str.c_str();
    char* endptr;

    std::strtod(cstr, &endptr);
    if (endptr == cstr)
        return false;
	if (endptr[0] == 'f' && endptr[1] == 'f')
		return false;
	while (*endptr != '\0')
    {
        if (*endptr != 'f')
            return false;
        ++endptr;
	}
    return true;
}

const std::string trimString(const std::string &input) {
    std::string result = input;
    
    size_t start = 0;
    while (start < result.size() && result[start] == '0') {
        if (result[start + 1] == '.') break;
        start++;
    }
    result = result.substr(start);

    size_t end = result.size();
    while (end > 0 && result[end - 1] == 'f') {
        end--;
    }
    result = result.substr(0, end);

    return result;
}

double Utils::strToDouble(const std::string& str) {
    double result;

	const std::string nbr = trimString(str);
    std::stringstream ss(nbr);
    ss >> result;
    if (ss.fail()) {
        return -1;
    }
    return result;
}


float Utils::strToFloat(const std::string& str) {
    float result;

	const std::string nbr = trimString(str);
    std::stringstream ss(nbr);

    ss >> result;
    if (ss.fail()) {
        return -1;
    }
    return result;
}

int Utils::strToInt(const std::string& str) {
    std::stringstream ss(str);
    int result;

    ss >> result;
    if (ss.fail()) {
        return -1;
    }
    return result;
}