#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"


class WrongCat: public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();
	WrongCat &operator=(const WrongCat &src);
	void makeSound(void)const;

};

#endif