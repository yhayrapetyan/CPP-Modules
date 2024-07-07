#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

typedef std::string string;

class	ICharacter;

class AMateria  {

public:
	AMateria();
	AMateria(string const &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter& target) = 0;

protected:
	string			_type;
};


#endif