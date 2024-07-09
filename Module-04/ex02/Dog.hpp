#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	
	virtual void makeSound() const;
	void 	think(string idea, unsigned int i);
	string	remember(unsigned int i);
	
private:
	Brain   *_brain;

};

#endif