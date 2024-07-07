#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "Default constructor for AMateria\n";
}

AMateria::~AMateria() {
	std::cout << "Destructor for AMateria\n";
}

AMateria::AMateria(const AMateria &other) {
	std::cout << "Copy constructor for AMateria\n";
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << "Copy assignment operator for AMateria\n";
	_type = other._type;
	return (*this);
}

AMateria::AMateria(string const &type) {
	this->_type = type;
	std::cout << "Type constructor for AMateria " << "[" << this->_type << "]\n";
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) { (void) target; }