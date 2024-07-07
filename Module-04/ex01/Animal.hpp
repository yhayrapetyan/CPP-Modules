#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

typedef std::string string;

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(Animal &aniaml);
	Animal &operator=(const Animal &other);
	Animal(const string& type);

	virtual void makeSound() const;
	string getType() const;


protected:
	string	_type;
};

#endif