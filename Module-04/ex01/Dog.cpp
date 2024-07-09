#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor\n";
	this->_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor\n";
	delete this->_brain;
}

Dog::Dog(const Dog &other) : Animal(), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog copy assign constructor\n";
	if (this == &src)
		return *this;
	*_brain = *src._brain;
	return *this;
}

void Dog::makeSound() const { std::cout << this->getType() << " says: Bark\n"; }

void Dog::think(string idea, unsigned int i) {
	this->_brain->set_idea(idea, i);
}

string	Dog::remember(unsigned int i) {
	return this->_brain->get_idea(i);
}