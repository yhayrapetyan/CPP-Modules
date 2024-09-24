#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor\n";
	this->_brain = new Brain();
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor\n";
	this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &src) {
	std::cout << "Cat copy assign constructor\n";
	if (this == &src)
		return *this;
	delete this->_brain;
	this->_brain =  new Brain(*src._brain);
	return *this;
}

void Cat::makeSound() const { std::cout << this->getType() << " says: Meow\n"; }

void Cat::think(string idea, unsigned int i) {
	this->_brain->set_idea(idea, i);
}

string	Cat::remember(unsigned int i) {
	return this->_brain->get_idea(i);
}