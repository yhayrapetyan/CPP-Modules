#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor\n";
	this->_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor\n";
	delete this->_brain;
}

Cat::Cat(Cat &other) : Animal() {
	std::cout << "Cat copy constructor\n";
	*this = other;
}

Cat &Cat::operator=(const Cat &src) {
	std::cout << "Cat copy assign constructor\n";
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void Cat::makeSound() const { std::cout << this->getType() << " says: Meow\n"; }