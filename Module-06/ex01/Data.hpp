#ifndef DATA_H
# define DATA_H

#include <iostream>

class Data {
public:
	Data();
	~Data();
	Data(const Data &copy);
	Data &operator=(const Data &other);
    int value;
};

#endif