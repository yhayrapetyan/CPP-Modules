#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	this->_size = 0;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	std::cout << "Default constructor for MateriaSource\n";
}

MateriaSource::~MateriaSource() {
	std::cout << "Destructor for MateriaSource\n";
	for (int i = 0; i < this->_size; ++i)
		delete this->_materias[i];
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "Copy constructor for MateriaSource\n";
	*this = other;
	for (int i = 0; i < this->_size; ++i)
		this->_materias[i] = other._materias[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "Copy assignment operator for MateriaSource\n";
	this->_size = other._size;
	for (int i = 0; i < this->_size; ++i)
		this->_materias[i] = other._materias[i]->clone();
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (!materia) {
		std::cout << "Error No materia specified\n";
		return;
	}
	if (this->_size < 4)
		this->_materias[(this->_size)++] = materia;
	else
		std::cout << "No place left only 4 items\n";
}

AMateria *MateriaSource::createMateria(string const &type) {
	for (int i = 0; i < this->_size; ++i)
		if (type == this->_materias[i]->getType())
			return (this->_materias[i]->clone());
	return (NULL);
}