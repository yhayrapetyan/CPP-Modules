#ifndef UTILS_H
# define UTILS_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>

typedef std::string string;

class Utils  {
private:
	Utils();
	Utils(const Utils &copy);
	Utils &operator=(const Utils &other);
	~Utils();

public:
	

	static bool check_limits(const string &str);
	static bool chekcOverflow(string str);
	static bool isInt(const string& str);
	static bool isChar(const string& str);
	static bool isFloat(const string& str);
	static bool isDouble(const string& str);
	
	static int		strToInt(const string &str);
	static float	strToFloat(const string &str);
	static double	strToDouble(const string &str);

};

#endif