#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

typedef std::string string;

class Animal
{
public:
	virtual ~Animal();
	Animal &operator=(const Animal &other);

	virtual void makeSound() const;
	string getType() const;

protected:
	Animal();
	Animal(Animal &aniaml);
	Animal(const string& type);

	string	_type;
};

#endif