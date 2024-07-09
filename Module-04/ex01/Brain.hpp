#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

typedef std::string string;

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	string &operator[](unsigned int i);
	void	set_idea(string idea, unsigned int	i);
	string	get_idea(unsigned int i);

protected:
	string _ideas[100];

};

#endif