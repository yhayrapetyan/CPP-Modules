#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include <string>

class Cat : public Animal   {
public:
	Cat();
	Cat(const Cat &other);
	~Cat();
	Cat &operator=(const Cat &other);
	virtual void makeSound() const;
	string	get_type() const;

};

#endif