#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog(Dog &other);
	Dog &operator=(const Dog &other);
	virtual void makeSound() const;

private:
	Brain   *_brain;
};

#endif