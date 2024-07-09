#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual void makeSound() const;

};

#endif