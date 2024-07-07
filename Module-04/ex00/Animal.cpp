#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor\n";
	this->_type = "Animal";
}

Animal::~Animal(){
	std::cout << "Animal destructor\n";
}

Animal::Animal(Animal &other)  {
	std::cout << "Animal copy constructor\n";
	*this = other;
}


Animal   &Animal::operator=(const Animal &other)  {
	std::cout << "Animal copy assign constructor\n";
	this->_type = other._type;
	return (*this);
}

Animal::Animal(const string &type) {
	std::cout << "Animal main constructor\n";
	this->_type = type;
}

string Animal::getType() const{return this->_type;}
void Animal::makeSound() const{std::cout << this->getType() << " says: Animal sound\n";}