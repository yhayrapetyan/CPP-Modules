#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

typedef std::string string;

class Brain {
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	std::string &operator[](unsigned int i);

protected:
	string *_ideas;
};

#endif