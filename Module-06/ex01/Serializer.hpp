
#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>
#include "Data.hpp"

class Data;

class Serializer  {
public:
	static uintptr_t    serialize(Data *ptr);
	static Data         *deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &other);
	~Serializer();

};
#endif