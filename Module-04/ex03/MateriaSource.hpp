#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	void		learnMateria(AMateria *materia);
	AMateria    *createMateria(string const &type);

private:
	int         _size;
	AMateria    *_materias[4];
};
#endif