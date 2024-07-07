#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

typedef std::string string;

class Character : public ICharacter{

public:
	Character();
	Character(const string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	string const		&getName() const;
	void				equip(AMateria *item);
	void				unequip(int i);
	void				use(int i, ICharacter &target);

private:
	string 		_name;
	int         _size;
	AMateria    *_inventory[4];
};
#endif