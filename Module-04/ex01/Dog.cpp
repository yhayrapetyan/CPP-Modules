#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor\n";
	this->_brain = new Brain();
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor\n";
}

Dog::Dog(const Dog &other) : Animal(other){
	std::cout << "Dog copy constructor\n";
	this->_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog copy assign constructor\n";
	if (this == &src)
		return *this;
	delete this->_brain;
	this->_brain =  new Brain(*src._brain);
	return *this;
}

void Dog::makeSound() const { std::cout << this->getType() << " says: Bark\n"; }

void Dog::think(string idea, unsigned int i) {
	this->_brain->set_idea(idea, i);
}

string	Dog::remember(unsigned int i) {
	return this->_brain->get_idea(i);
}