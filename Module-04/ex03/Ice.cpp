#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout  << "Default constructor for Ice\n";
}

Ice::~Ice() {
	std::cout  << "Default destructor for Ice\n";
}

Ice::Ice(const Ice &other) : AMateria(other) {
	std::cout << "Copy constructor for Cure\n";
	*this = other;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Copy assignment operator for Ice\n";
	AMateria::operator=(other);
	return (*this);
}

AMateria *Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter &target) {
	std::cout << "\n* shoots an ice bolt at  " << target.getName() << " *\n\n";
}