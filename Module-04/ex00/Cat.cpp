#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat default constructor\n"; }

Cat::~Cat() { std::cout << "Cat destructor\n"; }

Cat::Cat(const Cat &other) : Animal() {
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

void 	Cat::makeSound() const { std::cout << this->getType() << " says: Meow\n"; }
string	Cat::get_type() const { return this->_type; }