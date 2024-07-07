#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Default constructor for Cure\n";
}

Cure::~Cure() {
	std::cout << "Destructor for Cure\n";
}

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cout << "Copy constructor for Cure\n";
	*this = other;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << "Copy assignment operator for Cure\n";
	AMateria::operator=(other);
	return (*this);
}

AMateria *Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter &target) {
	std::cout << "\n* heals  " << target.getName() << "'s wounds *\n\n";
}