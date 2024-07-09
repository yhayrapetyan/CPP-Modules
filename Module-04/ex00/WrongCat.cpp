#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat Default Constructor called\n";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal() {
	std::cout << "WrongCat Copy Constructor called\n";
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Deconstructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	std::cout << "WrongCat Assignation operator called\n";
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << this->getType() << " says: **WrongCat sounds**\n";
}