#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->_type = "Wrong Animal";
	std::cout << "WrongAnimal Default Constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal Copy Constructor called\n";
	*this = copy;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	std::cout << "WrongAnimal Assignation operator called\n";
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << this->getType() << " says: **WrongAnimal sounds**\n";
}

std::string WrongAnimal::getType(void) const {
	return (this->_type);
}
