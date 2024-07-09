#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal   {
public:
	Cat();
	Cat(const Cat &other);
	virtual ~Cat();
	Cat &operator=(const Cat &other);
	
	virtual void makeSound() const;
	void 	think(string idea, unsigned int i);
	string	remember(unsigned int i);

private:
	Brain   *_brain;

};
#endif