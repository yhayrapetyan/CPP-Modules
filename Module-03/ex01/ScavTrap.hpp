#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(string name);
	ScavTrap(const ScavTrap &scavtrap);
	ScavTrap& operator=(const ScavTrap &scavtrap);
	virtual ~ScavTrap();

	void    attack(const string &target);
	void    guardGate(void);

};


#endif