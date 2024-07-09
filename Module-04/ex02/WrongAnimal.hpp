#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>
#include <iostream>

typedef std::string string;

class WrongAnimal{
protected:
	string _type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &src);

	void makeSound(void)const;
	string getType(void)const;

};

#endif