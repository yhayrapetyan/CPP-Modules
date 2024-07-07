#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal   {

public:
	Cat();
	Cat(Cat &other);
	~Cat();
	Cat &operator=(const Cat &other);
	virtual void makeSound() const;
};
#endif