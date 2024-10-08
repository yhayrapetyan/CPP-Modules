#ifndef ICHARACTER_H
# define ICHARACTER_H

#include "AMateria.hpp"

typedef std::string string;

class AMateria;

class ICharacter {
public:
	virtual 					~ICharacter() {}
	virtual	string const		&getName() const = 0;
	virtual void				equip(AMateria *m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter &target) = 0;
};

#endif