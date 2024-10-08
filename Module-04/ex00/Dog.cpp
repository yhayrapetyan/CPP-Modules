#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor\n";
}

Dog::~Dog() {
	std::cout << "Dog destructor\n";
}

Dog::Dog(const Dog &other) : Animal() {
	std::cout << "Dog copy constructor\n";
	*this = other;
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog copy asign constructor\n";
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void Dog::makeSound() const { std::cout << this->getType() << " says: Bark\n"; }
